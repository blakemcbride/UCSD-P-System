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

Fedora packages needed:

    sudo dnf install meson ninja-build gcc-c++ bison boost-devel fuse-devel \
        libpng-devel ncurses-devel libX11-devel libXt-devel python3 sharutils

Then:

    make            # native tools, then the p-System volumes
    make test       # run the native test suites
    make run        # boot the built system in the VM (uses copies in run/)
    make install    # install under PREFIX (default /usr/local)
    make clean      # remove build output
    make distclean  # also remove run/ (VM working volumes)

The build happens in two stages:

1. `build/` holds the native Meson build. The top-level `meson.build`
   pulls in xc, fs and vm as subprojects.
2. `build-os/` holds a cross build of `os/` for the p-machine. It uses the
   tools from stage 1 and produces `system.vol`, `utility.vol` and
   `diagnostic.vol`.

## License

Components keep their original licenses (GPL for the Unix tools, the UCSD
license for the p-System itself). See `LICENSE`.

## Notes

- libexplain is no longer packaged for Fedora. `subprojects/libexplain`
  implements the subset of its API that these tools use. If a real libexplain
  is installed, it is used instead.
- The C++ code predates C++20, so it's compiled as `gnu++17`.
