# UCSD-P-System

The UCSD Pascal p-System II.0 together with the host tools needed to build
and run it. It combines four projects that used to be separate:

| Directory                           | Was               | Contents                                      |
|-------------------------------------|-------------------|-----------------------------------------------|
| `subprojects/ucsd-psystem-xc`       | ucsd-psystem-xc   | Cross compiler, assembler, linker, librarian  |
| `subprojects/ucsd-psystem-fs`       | ucsd-psystem-fs   | Disk-image tools (mkfs, disk, fsck, mount)    |
| `subprojects/ucsd-psystem-vm`       | ucsd-psystem-vm   | p-machine virtual machine                     |
| `os`                                | ucsd-psystem-os   | p-System sources, built into disk volumes     |
| `subprojects/libexplain`            | (new)             | Small stand-in for libexplain                 |

## Building

Required: a C and C++17 compiler and GNU make 3.81 or later.

The bison-generated parsers are checked in. If bison 3 or later is installed,
they are regenerated whenever a `grammar.y` changes; otherwise the checked-in
copies are used.

Optional (SDL3, FUSE and libpng are used when `pkg-config` finds them;
curses is on unless turned off):

| Library  | Needed for                                          | Force with       |
|----------|-----------------------------------------------------|------------------|
| SDL3     | The VM's console window (text and turtle graphics), `ucsdpsys_turtleserver` | `SDL=yes\|no`    |
| curses   | The VM's terminal console                           | `CURSES=yes\|no` |
| FUSE 2   | `ucsdpsys_mount`, `ucsdpsys_umount`                 | `FUSE=yes\|no`   |
| libpng   | PNG support in `ucsdpsys_foto`, `ucsdpsys_charset`  | `PNG=yes\|no`    |

At least one of SDL3 and curses is needed to use the system interactively.

Packages:

    # Fedora
    sudo dnf install make gcc-c++ ncurses-devel \
        pkgconf fuse-devel SDL3-devel libpng-devel
    # Debian / Ubuntu
    sudo apt install make g++ libncurses-dev \
        pkg-config libfuse-dev libsdl3-dev libpng-dev
    # macOS (Homebrew)
    brew install pkg-config sdl3 libpng

Add `bison` (version 3 or later) only if you will change a grammar.

On the BSDs, use `gmake`.

Then:

    make            # native tools, then the p-System volumes
    make test       # run the native test suites
    make run        # boot the built system in the VM (uses copies in run/)
    make install    # install under PREFIX (default /usr/local)
    make clean      # remove build output
    make distclean  # also remove run/ (VM working volumes)

Use `make -j8` (or similar) for a parallel build. `PREFIX`, `DESTDIR`, `CC`,
`CXX`, `CFLAGS` and `CXXFLAGS` work as usual.

Everything goes into `build/`: the tools in `build/bin`, and the volumes
`system.vol`, `utility.vol` and `diagnostic.vol` in `build/`. The volumes are
compiled from `os/` by the freshly built tools.

## Running

`make run` boots the system. With SDL3 and a display, the VM opens an 80×24
console window; otherwise it runs in the terminal. The VM writes to its
volumes, so `make run` boots from copies in `run/`; once they exist you can
also run it directly:

    build/bin/ucsdpsys_vm -w run/system.vol -w run/utility.vol

- `--terminal` uses the terminal even when a window could be opened.
- `-b file` (or `-b -` for stdin) runs in batch mode: keys from the file,
  output to stdout, no screen control. The tests use this.
- H(alt) at the command prompt ends the system; closing the window does too.

Turtle graphics appear in the console window: `INITTURTLE` and `GRAFMODE`
show the graphics screen, `TEXTMODE` the text. F2 switches between them at
any time; use it after a graphics program ends, since the system doesn't
return to text by itself. In the terminal, turtle graphics open a separate
`ucsdpsys_turtleserver` window instead.

II.0 has no intrinsic units, so a program that `uses turtlegr` must carry
the unit (segment 15) in its own code file:

    ucsdpsys_compile --arch=p-code-le prog.text
    ucsdpsys_librarian --create prog2.code --copy prog.code --segment prog=1 \
        --copy build/os/system/system.library --segment turtlegr=15

## License

Components keep their original licenses (GPL for the Unix tools, the UCSD
license for the p-System itself). See `LICENSE`.

## Notes

- libexplain is no longer packaged by most distributions.
  `subprojects/libexplain` implements the subset of its API that these tools
  use, and is always used.
- The C++ code predates C++20, so it's compiled as `c++17`.
