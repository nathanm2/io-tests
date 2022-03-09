project('io-test', ['c'],
  default_options: ['werror=true', 'buildtype=debugoptimized'],
  version: '0.1.1')

glib_dep = dependency('glib-2.0', version: '>=2.44.0',
  default_options: ['werror=false'],
  fallback: ['glib', 'libglib_dep'])

# Basic IO writer
executable('basic', 'basic.c', dependencies: [glib_dep])
