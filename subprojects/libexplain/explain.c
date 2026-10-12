/*
 * Minimal libexplain compatibility shim for the UCSD p-System tools.
 * See libexplain/libexplain.h.
 */
#define _GNU_SOURCE
#include <libexplain/libexplain.h>

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <syslog.h>
#include <unistd.h>

struct explain_output_t
{
    int dummy;
};

static char program_name[256];
static int use_syslog;
static int hanging_indent;
static char message[PATH_MAX + 1024];


void
explain_program_name_set(const char *name)
{
    const char *slash;

    if (!name)
        name = "";
    slash = strrchr(name, '/');
    if (slash)
        name = slash + 1;
    snprintf(program_name, sizeof(program_name), "%s", name);
}


const char *
explain_program_name_get(void)
{
    if (!program_name[0])
        explain_program_name_set(program_invocation_name);
    return program_name;
}


void
explain_option_hanging_indent_set(int columns)
{
    hanging_indent = columns < 0 ? 0 : columns;
}


/*
 * Print "prog: text" to stderr, filling lines to at most LINE_WIDTH
 * columns and indenting continuation lines by the hanging indent, the
 * same way libexplain does.
 */
#define LINE_WIDTH 75

static void
wrap_and_print(const char *prog, const char *text)
{
    const char *p = text;
    int col;

    fprintf(stderr, "%s:", prog);
    col = strlen(prog) + 1;
    for (;;)
    {
        const char *word;
        int len;

        while (*p == ' ' || *p == '\t' || *p == '\n')
            ++p;
        if (!*p)
            break;
        word = p;
        while (*p && *p != ' ' && *p != '\t' && *p != '\n')
            ++p;
        len = p - word;
        if (col + 1 + len > LINE_WIDTH && col > hanging_indent)
        {
            fprintf(stderr, "\n%*s", hanging_indent, "");
            col = hanging_indent;
            if (col > 0)
            {
                fprintf(stderr, "%.*s", len, word);
                col += len;
                continue;
            }
        }
        else
        {
            fputc(' ', stderr);
            ++col;
        }
        fprintf(stderr, "%.*s", len, word);
        col += len;
    }
    fputc('\n', stderr);
}


void
explain_output_message(const char *text)
{
    if (use_syslog)
    {
        syslog(LOG_ERR, "%s", text);
        return;
    }
    fflush(stdout);
    wrap_and_print(explain_program_name_get(), text);
    fflush(stderr);
}


static void
vmessage(const char *prefix, const char *fmt, va_list ap)
{
    char buf[4096];
    size_t n;

    snprintf(buf, sizeof(buf), "%s", prefix);
    n = strlen(buf);
    vsnprintf(buf + n, sizeof(buf) - n, fmt, ap);
    explain_output_message(buf);
}


void
explain_output_error(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vmessage("", fmt, ap);
    va_end(ap);
}


void
explain_output_error_and_die(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vmessage("", fmt, ap);
    va_end(ap);
    explain_output_exit_failure();
}


void
explain_output_warning(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vmessage("warning: ", fmt, ap);
    va_end(ap);
}


void
explain_output_exit_failure(void)
{
    exit(EXIT_FAILURE);
}


explain_output_t *
explain_output_syslog_new(void)
{
    static explain_output_t syslog_output;

    return &syslog_output;
}


void
explain_output_register(explain_output_t *op)
{
    use_syslog = (op != NULL);
    if (use_syslog)
        openlog(explain_program_name_get(), LOG_PID, LOG_USER);
}


/*
 * Formatting helpers.  Each saves errno, builds a message of the form
 * "call(args) failed, strerror" into the static buffer and returns it.
 */

static const char *
fail(const char *fmt, ...)
{
    int err = errno;
    va_list ap;
    size_t n;

    va_start(ap, fmt);
    vsnprintf(message, sizeof(message), fmt, ap);
    va_end(ap);
    n = strlen(message);
    snprintf(message + n, sizeof(message) - n, " failed, %s (%d, %s)",
        strerror(err), err, strerrorname_np(err) ? strerrorname_np(err) : "?");
    errno = err;
    return message;
}


#define DIE(...) \
    do { \
        explain_output_message(fail(__VA_ARGS__)); \
        explain_output_exit_failure(); \
    } while (0)

#define REPORT(...) explain_output_message(fail(__VA_ARGS__))


static const char *
stream_name(FILE *fp)
{
    static char buf[PATH_MAX + 1];

    if (explain_filename_from_stream(fp, buf, sizeof(buf)) < 0)
        snprintf(buf, sizeof(buf), "fildes %d", fp ? fileno(fp) : -1);
    return buf;
}


static const char *
fd_name(int fildes)
{
    static char buf[PATH_MAX + 1];
    char proc[64];
    ssize_t n;

    snprintf(proc, sizeof(proc), "/proc/self/fd/%d", fildes);
    n = readlink(proc, buf, sizeof(buf) - 1);
    if (n < 0)
        snprintf(buf, sizeof(buf), "%d", fildes);
    else
        buf[n] = '\0';
    return buf;
}


/*
 * Append libexplain's explanation for the common ENOENT case, where the
 * final path component does not exist.
 */
static const char *
because_enoent(const char *pathname)
{
    const char *slash;
    size_t n;

    if (errno != ENOENT)
        return message;
    n = strlen(message);
    slash = strrchr(pathname, '/');
    if (!slash)
    {
        snprintf(message + n, sizeof(message) - n, " because there is no "
            "\"%s\" regular file in the current directory", pathname);
    }
    else
    {
        snprintf(message + n, sizeof(message) - n, " because there is no "
            "\"%s\" regular file in the \"%.*s\" directory", slash + 1,
            (int)(slash == pathname ? 1 : slash - pathname), pathname);
    }
    return message;
}


const char *
explain_fopen(const char *pathname, const char *flags)
{
    fail("fopen(pathname = \"%s\", flags = \"%s\")", pathname, flags);
    return because_enoent(pathname);
}


static const char *
open_flags_name(int flags)
{
    static const struct { int bit; const char *name; } table[] =
    {
        { O_CREAT, "O_CREAT" },
        { O_EXCL, "O_EXCL" },
        { O_NOCTTY, "O_NOCTTY" },
        { O_TRUNC, "O_TRUNC" },
        { O_APPEND, "O_APPEND" },
        { O_NONBLOCK, "O_NONBLOCK" },
        { O_SYNC, "O_SYNC" },
        { O_DIRECTORY, "O_DIRECTORY" },
        { O_NOFOLLOW, "O_NOFOLLOW" },
        { O_CLOEXEC, "O_CLOEXEC" },
    };
    static char buf[256];
    size_t j;

    switch (flags & O_ACCMODE)
    {
    case O_RDONLY: snprintf(buf, sizeof(buf), "O_RDONLY"); break;
    case O_WRONLY: snprintf(buf, sizeof(buf), "O_WRONLY"); break;
    default: snprintf(buf, sizeof(buf), "O_RDWR"); break;
    }
    flags &= ~O_ACCMODE;
    for (j = 0; j < sizeof(table) / sizeof(table[0]); ++j)
    {
        if ((flags & table[j].bit) == table[j].bit)
        {
            size_t n = strlen(buf);
            snprintf(buf + n, sizeof(buf) - n, " | %s", table[j].name);
            flags &= ~table[j].bit;
        }
    }
    if (flags)
    {
        size_t n = strlen(buf);
        snprintf(buf + n, sizeof(buf) - n, " | %#o", flags);
    }
    return buf;
}


const char *
explain_open(const char *pathname, int flags, int mode)
{
    if (flags & O_CREAT)
        fail("open(pathname = \"%s\", flags = %s, mode = %#o)", pathname,
            open_flags_name(flags), mode);
    else
        fail("open(pathname = \"%s\", flags = %s)", pathname,
            open_flags_name(flags));
    return because_enoent(pathname);
}


const char *
explain_unlink(const char *pathname)
{
    return fail("unlink(pathname = \"%s\")", pathname);
}


int
explain_filename_from_stream(FILE *fp, char *data, size_t data_size)
{
    char proc[64];
    ssize_t n;
    int fd;

    if (!fp || !data || data_size < 2)
        return -1;
    fd = fileno(fp);
    if (fd < 0)
        return -1;
    snprintf(proc, sizeof(proc), "/proc/self/fd/%d", fd);
    n = readlink(proc, data, data_size - 1);
    if (n < 0)
        return -1;
    data[n] = '\0';
    return 0;
}


int
explain_fstat_on_error(int fildes, struct stat *data)
{
    int rc = fstat(fildes, data);
    if (rc < 0)
        REPORT("fstat(fildes = %d \"%s\")", fildes, fd_name(fildes));
    return rc;
}


ssize_t
explain_read_on_error(int fildes, void *data, size_t data_size)
{
    ssize_t rc = read(fildes, data, data_size);
    if (rc < 0)
        REPORT("read(fildes = %d \"%s\", data_size = %zu)", fildes,
            fd_name(fildes), data_size);
    return rc;
}


int
explain_socketpair_on_error(int domain, int type, int protocol, int *sv)
{
    int rc = socketpair(domain, type, protocol, sv);
    if (rc < 0)
        REPORT("socketpair(domain = %d, type = %d, protocol = %d)", domain,
            type, protocol);
    return rc;
}


pid_t
explain_fork_on_error(void)
{
    pid_t rc = fork();
    if (rc < 0)
        REPORT("fork()");
    return rc;
}


int
explain_gettimeofday_on_error(struct timeval *tv, void *tz)
{
    int rc = gettimeofday(tv, tz);
    if (rc < 0)
        REPORT("gettimeofday()");
    return rc;
}


int
explain_accept_or_die(int fildes, struct sockaddr *sock_addr,
    socklen_t *sock_addr_size)
{
    int rc = accept(fildes, sock_addr, sock_addr_size);
    if (rc < 0)
        DIE("accept(fildes = %d)", fildes);
    return rc;
}


void
explain_bind_or_die(int fildes, const struct sockaddr *sock_addr,
    socklen_t sock_addr_size)
{
    if (bind(fildes, sock_addr, sock_addr_size) < 0)
        DIE("bind(fildes = %d)", fildes);
}


void
explain_chmod_or_die(const char *pathname, int mode)
{
    if (chmod(pathname, mode) < 0)
        DIE("chmod(pathname = \"%s\", mode = %#o)", pathname, mode);
}


void
explain_close_or_die(int fildes)
{
    if (close(fildes) < 0)
        DIE("close(fildes = %d)", fildes);
}


void
explain_closedir_or_die(DIR *dir)
{
    if (closedir(dir) < 0)
        DIE("closedir()");
}


int
explain_creat_or_die(const char *pathname, int mode)
{
    int rc = creat(pathname, mode);
    if (rc < 0)
        DIE("creat(pathname = \"%s\", mode = %#o)", pathname, mode);
    return rc;
}


void
explain_execlp_or_die(const char *pathname, const char *arg, ...)
{
    const char *argv[256];
    va_list ap;
    int argc = 0;

    argv[argc++] = arg;
    va_start(ap, arg);
    while (argc < 255 && argv[argc - 1] != NULL)
        argv[argc++] = va_arg(ap, const char *);
    va_end(ap);
    argv[argc] = NULL;
    execvp(pathname, (char *const *)argv);
    DIE("execlp(pathname = \"%s\")", pathname);
}


void
explain_fclose_or_die(FILE *fp)
{
    char name[PATH_MAX + 1];

    snprintf(name, sizeof(name), "%s", stream_name(fp));
    if (fflush(fp) != 0)
    {
        int err = errno;
        fclose(fp);
        errno = err;
        DIE("fclose(fp = \"%s\")", name);
    }
    if (fclose(fp) != 0)
        DIE("fclose(fp = \"%s\")", name);
}


void
explain_fflush_or_die(FILE *fp)
{
    if (fflush(fp) != 0)
        DIE("fflush(fp = \"%s\")", stream_name(fp));
}


char *
explain_fgets_or_die(char *data, int data_size, FILE *fp)
{
    char *rc = fgets(data, data_size, fp);
    if (!rc && ferror(fp))
        DIE("fgets(fp = \"%s\")", stream_name(fp));
    return rc;
}


FILE *
explain_fopen_or_die(const char *pathname, const char *flags)
{
    FILE *fp = fopen(pathname, flags);
    if (!fp)
    {
        explain_output_message(explain_fopen(pathname, flags));
        explain_output_exit_failure();
    }
    return fp;
}


void
explain_fputc_or_die(int c, FILE *fp)
{
    if (fputc(c, fp) == EOF)
        DIE("fputc(fp = \"%s\")", stream_name(fp));
}


size_t
explain_fread_or_die(void *ptr, size_t size, size_t nmemb, FILE *fp)
{
    size_t rc = fread(ptr, size, nmemb, fp);
    if (rc < nmemb && ferror(fp))
        DIE("fread(fp = \"%s\")", stream_name(fp));
    return rc;
}


FILE *
explain_freopen_or_die(const char *pathname, const char *flags, FILE *fp)
{
    FILE *rc = freopen(pathname, flags, fp);
    if (!rc)
        DIE("freopen(pathname = \"%s\", flags = \"%s\")", pathname, flags);
    return rc;
}


void
explain_fseek_or_die(FILE *fp, long offset, int whence)
{
    if (fseek(fp, offset, whence) < 0)
        DIE("fseek(fp = \"%s\", offset = %ld, whence = %d)", stream_name(fp),
            offset, whence);
}


void
explain_fstat_or_die(int fildes, struct stat *data)
{
    if (fstat(fildes, data) < 0)
        DIE("fstat(fildes = %d \"%s\")", fildes, fd_name(fildes));
}


void
explain_ftruncate_or_die(int fildes, off_t length)
{
    if (ftruncate(fildes, length) < 0)
        DIE("ftruncate(fildes = %d \"%s\", length = %lld)", fildes,
            fd_name(fildes), (long long)length);
}


size_t
explain_fwrite_or_die(const void *ptr, size_t size, size_t nmemb, FILE *fp)
{
    size_t rc = fwrite(ptr, size, nmemb, fp);
    if (rc < nmemb)
        DIE("fwrite(fp = \"%s\")", stream_name(fp));
    return rc;
}


int
explain_getc_or_die(FILE *fp)
{
    int c = getc(fp);
    if (c == EOF && ferror(fp))
        DIE("getc(fp = \"%s\")", stream_name(fp));
    return c;
}


char *
explain_getcwd_or_die(char *data, size_t data_size)
{
    char *rc = getcwd(data, data_size);
    if (!rc)
        DIE("getcwd()");
    return rc;
}


void
explain_getsockname_or_die(int fildes, struct sockaddr *sock_addr,
    socklen_t *sock_addr_size)
{
    if (getsockname(fildes, sock_addr, sock_addr_size) < 0)
        DIE("getsockname(fildes = %d)", fildes);
}


void
explain_gettimeofday_or_die(struct timeval *tv, void *tz)
{
    if (gettimeofday(tv, tz) < 0)
        DIE("gettimeofday()");
}


void
explain_listen_or_die(int fildes, int backlog)
{
    if (listen(fildes, backlog) < 0)
        DIE("listen(fildes = %d, backlog = %d)", fildes, backlog);
}


off_t
explain_lseek_or_die(int fildes, off_t offset, int whence)
{
    off_t rc = lseek(fildes, offset, whence);
    if (rc == (off_t)-1)
        DIE("lseek(fildes = %d \"%s\", offset = %lld, whence = %d)", fildes,
            fd_name(fildes), (long long)offset, whence);
    return rc;
}


void *
explain_malloc_or_die(size_t size)
{
    void *rc = malloc(size ? size : 1);
    if (!rc)
        DIE("malloc(size = %zu)", size);
    return rc;
}


void *
explain_mmap_or_die(void *data, size_t data_size, int prot, int flags,
    int fildes, off_t offset)
{
    void *rc = mmap(data, data_size, prot, flags, fildes, offset);
    if (rc == MAP_FAILED)
        DIE("mmap(data_size = %zu, fildes = %d \"%s\")", data_size, fildes,
            fd_name(fildes));
    return rc;
}


void
explain_munmap_or_die(void *data, size_t data_size)
{
    if (munmap(data, data_size) < 0)
        DIE("munmap(data_size = %zu)", data_size);
}


int
explain_open_or_die(const char *pathname, int flags, int mode)
{
    int rc = open(pathname, flags, mode);
    if (rc < 0)
    {
        explain_output_message(explain_open(pathname, flags, mode));
        explain_output_exit_failure();
    }
    return rc;
}


DIR *
explain_opendir_or_die(const char *pathname)
{
    DIR *rc = opendir(pathname);
    if (!rc)
        DIE("opendir(pathname = \"%s\")", pathname);
    return rc;
}


void
explain_pclose_success_or_die(FILE *fp)
{
    int status = pclose(fp);
    if (status < 0)
        DIE("pclose()");
    if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
    {
        explain_output_error_and_die("pclose(): child process failed "
            "(status %#x)", status);
    }
}


FILE *
explain_popen_or_die(const char *command, const char *flags)
{
    FILE *rc = popen(command, flags);
    if (!rc)
        DIE("popen(command = \"%s\", flags = \"%s\")", command, flags);
    return rc;
}


void
explain_putc_or_die(int c, FILE *fp)
{
    if (putc(c, fp) == EOF)
        DIE("putc(fp = \"%s\")", stream_name(fp));
}


ssize_t
explain_read_or_die(int fildes, void *data, size_t data_size)
{
    ssize_t rc = read(fildes, data, data_size);
    if (rc < 0)
        DIE("read(fildes = %d \"%s\", data_size = %zu)", fildes,
            fd_name(fildes), data_size);
    return rc;
}


struct dirent *
explain_readdir_or_die(DIR *dir)
{
    struct dirent *rc;

    errno = 0;
    rc = readdir(dir);
    if (!rc && errno != 0)
        DIE("readdir()");
    return rc;
}


void
explain_rename_or_die(const char *oldpath, const char *newpath)
{
    if (rename(oldpath, newpath) < 0)
        DIE("rename(oldpath = \"%s\", newpath = \"%s\")", oldpath, newpath);
}


int
explain_socket_or_die(int domain, int type, int protocol)
{
    int rc = socket(domain, type, protocol);
    if (rc < 0)
        DIE("socket(domain = %d, type = %d, protocol = %d)", domain, type,
            protocol);
    return rc;
}


void
explain_stat_or_die(const char *pathname, struct stat *buf)
{
    if (stat(pathname, buf) < 0)
        DIE("stat(pathname = \"%s\")", pathname);
}


void
explain_statvfs_or_die(const char *pathname, struct statvfs *data)
{
    if (statvfs(pathname, data) < 0)
        DIE("statvfs(pathname = \"%s\")", pathname);
}


int
explain_system_or_die(const char *command)
{
    int status = system(command);
    if (status < 0)
        DIE("system(command = \"%s\")", command);
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    return status;
}


void
explain_system_success_or_die(const char *command)
{
    int status = system(command);
    if (status < 0)
        DIE("system(command = \"%s\")", command);
    if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
    {
        explain_output_error_and_die("system(command = \"%s\"): command "
            "failed (status %#x)", command, status);
    }
}


void
explain_unlink_or_die(const char *pathname)
{
    if (unlink(pathname) < 0)
    {
        explain_output_message(explain_unlink(pathname));
        explain_output_exit_failure();
    }
}


void
explain_utime_or_die(const char *pathname, const struct utimbuf *times)
{
    if (utime(pathname, times) < 0)
        DIE("utime(pathname = \"%s\")", pathname);
}


void
explain_utimes_or_die(const char *pathname, const struct timeval *data)
{
    if (utimes(pathname, data) < 0)
        DIE("utimes(pathname = \"%s\")", pathname);
}


ssize_t
explain_write_or_die(int fildes, const void *data, size_t data_size)
{
    ssize_t rc = write(fildes, data, data_size);
    if (rc < 0)
        DIE("write(fildes = %d \"%s\", data_size = %zu)", fildes,
            fd_name(fildes), data_size);
    return rc;
}
