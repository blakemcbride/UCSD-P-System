/*
 * Minimal libexplain compatibility shim for the UCSD p-System tools.
 *
 * The real libexplain (http://libexplain.sourceforge.net/) is no longer
 * packaged by most Linux distributions.  This library implements only the
 * subset of its API used by ucsd-psystem-fs, -vm and -xc.  Error messages
 * are "program: function(args): strerror(errno)" rather than libexplain's
 * detailed explanations.
 */
#ifndef LIBEXPLAIN_LIBEXPLAIN_H
#define LIBEXPLAIN_LIBEXPLAIN_H

#include <dirent.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <sys/time.h>
#include <sys/types.h>
#include <utime.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__GNUC__)
#define EXPLAIN_NORETURN __attribute__((noreturn))
#define EXPLAIN_PRINTF(a, b) __attribute__((format(printf, a, b)))
#else
#define EXPLAIN_NORETURN
#define EXPLAIN_PRINTF(a, b)
#endif
#define LIBEXPLAIN_FORMAT_PRINTF(a, b) EXPLAIN_PRINTF(a, b)

/* program name and options */
void explain_program_name_set(const char *name);
const char *explain_program_name_get(void);
void explain_option_hanging_indent_set(int columns);

/* output */
typedef struct explain_output_t explain_output_t;
void explain_output_message(const char *text);
void explain_output_error(const char *fmt, ...) EXPLAIN_PRINTF(1, 2);
void explain_output_error_and_die(const char *fmt, ...)
    EXPLAIN_PRINTF(1, 2) EXPLAIN_NORETURN;
void explain_output_warning(const char *fmt, ...) EXPLAIN_PRINTF(1, 2);
void explain_output_exit_failure(void) EXPLAIN_NORETURN;
explain_output_t *explain_output_syslog_new(void);
void explain_output_register(explain_output_t *op);

/* message-returning variants */
const char *explain_fopen(const char *pathname, const char *flags);
const char *explain_open(const char *pathname, int flags, int mode);
const char *explain_unlink(const char *pathname);
int explain_filename_from_stream(FILE *fp, char *data, size_t data_size);

/* *_on_error: report on failure, return the system call's result */
int explain_fstat_on_error(int fildes, struct stat *data);
ssize_t explain_read_on_error(int fildes, void *data, size_t data_size);
int explain_socketpair_on_error(int domain, int type, int protocol, int *sv);
pid_t explain_fork_on_error(void);
int explain_gettimeofday_on_error(struct timeval *tv, void *tz);

/* *_or_die: report and exit on failure */
int explain_accept_or_die(int fildes, struct sockaddr *sock_addr,
    socklen_t *sock_addr_size);
void explain_bind_or_die(int fildes, const struct sockaddr *sock_addr,
    socklen_t sock_addr_size);
void explain_chmod_or_die(const char *pathname, int mode);
void explain_close_or_die(int fildes);
void explain_closedir_or_die(DIR *dir);
int explain_creat_or_die(const char *pathname, int mode);
void explain_execlp_or_die(const char *pathname, const char *arg, ...)
    EXPLAIN_NORETURN;
void explain_fclose_or_die(FILE *fp);
void explain_fflush_or_die(FILE *fp);
char *explain_fgets_or_die(char *data, int data_size, FILE *fp);
FILE *explain_fopen_or_die(const char *pathname, const char *flags);
void explain_fputc_or_die(int c, FILE *fp);
size_t explain_fread_or_die(void *ptr, size_t size, size_t nmemb, FILE *fp);
FILE *explain_freopen_or_die(const char *pathname, const char *flags,
    FILE *fp);
void explain_fseek_or_die(FILE *fp, long offset, int whence);
void explain_fstat_or_die(int fildes, struct stat *data);
void explain_ftruncate_or_die(int fildes, off_t length);
size_t explain_fwrite_or_die(const void *ptr, size_t size, size_t nmemb,
    FILE *fp);
int explain_getc_or_die(FILE *fp);
char *explain_getcwd_or_die(char *data, size_t data_size);
void explain_getsockname_or_die(int fildes, struct sockaddr *sock_addr,
    socklen_t *sock_addr_size);
void explain_gettimeofday_or_die(struct timeval *tv, void *tz);
void explain_listen_or_die(int fildes, int backlog);
off_t explain_lseek_or_die(int fildes, off_t offset, int whence);
void *explain_malloc_or_die(size_t size);
void *explain_mmap_or_die(void *data, size_t data_size, int prot, int flags,
    int fildes, off_t offset);
void explain_munmap_or_die(void *data, size_t data_size);
int explain_open_or_die(const char *pathname, int flags, int mode);
DIR *explain_opendir_or_die(const char *pathname);
void explain_pclose_success_or_die(FILE *fp);
FILE *explain_popen_or_die(const char *command, const char *flags);
void explain_putc_or_die(int c, FILE *fp);
ssize_t explain_read_or_die(int fildes, void *data, size_t data_size);
struct dirent *explain_readdir_or_die(DIR *dir);
void explain_rename_or_die(const char *oldpath, const char *newpath);
int explain_socket_or_die(int domain, int type, int protocol);
void explain_stat_or_die(const char *pathname, struct stat *buf);
void explain_statvfs_or_die(const char *pathname, struct statvfs *data);
int explain_system_or_die(const char *command);
void explain_system_success_or_die(const char *command);
void explain_unlink_or_die(const char *pathname);
void explain_utime_or_die(const char *pathname, const struct utimbuf *times);
void explain_utimes_or_die(const char *pathname, const struct timeval *data);
ssize_t explain_write_or_die(int fildes, const void *data, size_t data_size);

#ifdef __cplusplus
}
#endif

#endif /* LIBEXPLAIN_LIBEXPLAIN_H */
