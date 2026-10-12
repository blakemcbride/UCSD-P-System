project('libexplain-shim', 'c', version : '1.4-shim', meson_version : '>=0.58.0')

# Minimal stand-in for libexplain, which is no longer packaged by most
# distributions.  Provides only the API subset the p-System tools use.

libexplain_inc = include_directories('.')

libexplain_lib = static_library(
  'explain',
  'explain.c',
  include_directories : libexplain_inc,
  pic : true,
)

libexplain_dep = declare_dependency(
  link_with : libexplain_lib,
  include_directories : libexplain_inc,
)

meson.override_dependency('libexplain', libexplain_dep)
