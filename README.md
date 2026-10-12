# UCSD-P-System

The UCSD Pascal p-System II.0 together with the Unix-hosted tools needed to
build and run it. It combines four projects that used to be separate:

| Directory                           | Was               | Contents                                      |
|-------------------------------------|-------------------|-----------------------------------------------|
| `subprojects/ucsd-psystem-xc`       | ucsd-psystem-xc   | Cross compiler, assembler, linker, librarian  |
| `subprojects/ucsd-psystem-fs`       | ucsd-psystem-fs   | Disk-image tools (mkfs, disk, fsck, mount)    |
| `subprojects/ucsd-psystem-vm`       | ucsd-psystem-vm   | p-machine virtual machine                     |
| `os`                                | ucsd-psystem-os   | p-System sources, built into disk volumes     |
| `subprojects/libexplain`            | (new)             | Small stand-in for libexplain                 |

## Building

Required: a C and C++17 compiler, GNU make 3.81 or later, and curses.

The bison-generated parsers are checked in. If bison 3 or later is installed,
they are regenerated whenever a `grammar.y` changes; otherwise the checked-in
copies are used.

Optional (built when `pkg-config` finds them):

| Library  | Needed for                                    | Force with      |
|----------|-----------------------------------------------|-----------------|
| FUSE 2   | `ucsdpsys_mount`, `ucsdpsys_umount`           | `FUSE=yes\|no`  |
| SDL3     | `ucsdpsys_turtleserver` (turtle graphics window) | `SDL=yes\|no` |
| libpng   | PNG support in `ucsdpsys_foto`, `ucsdpsys_charset` | `PNG=yes\|no` |

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

## License

Components keep their original licenses (GPL for the Unix tools, the UCSD
license for the p-System itself). See `LICENSE`.

## Notes

- libexplain is no longer packaged by most distributions.
  `subprojects/libexplain` implements the subset of its API that these tools
  use, and is always used.
- The C++ code predates C++20, so it's compiled as `c++17`.
- Turtle graphics: the VM starts `ucsdpsys_turtleserver` the first time a
  program calls the TURTLEGRAPHICS unit and draws in its window. Without a
  display it draws off screen; without the server, drawing is skipped.
  II.0 has no intrinsic units, so a program that `uses turtlegr` must carry
  the unit (segment 15) in its own code file:

      ucsdpsys_compile --arch=p-code-le prog.text
      ucsdpsys_librarian --create prog2.code --copy prog.code --segment prog=1 \
          --copy build/os/system/system.library --segment turtlegr=15
