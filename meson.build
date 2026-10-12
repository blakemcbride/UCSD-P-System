project('UCSD-P-System', 'c', 'cpp',
  meson_version : '>=0.64.0',
  # The C++ sources predate C++20 (e.g. 'requires' is used as an identifier).
  default_options : ['cpp_std=gnu++17', 'buildtype=debugoptimized'],
)

# Native (host) half of the UCSD p-System: the cross compiler (xc), the
# file system tools (fs) and the virtual machine (vm).  The p-System
# itself (os/) is built from these tools by a second, cross Meson build;
# see the top-level Makefile.

# Use the system libexplain when available, otherwise the bundled shim.
if not dependency('libexplain', required : false).found()
  subproject('libexplain')
endif

subproject('ucsd-psystem-fs')
subproject('ucsd-psystem-xc')
subproject('ucsd-psystem-vm')
