# Makefile.am - project helloac (Hello Autoconf)
# Inspired by my own article: https://www.linux.cz/noviny/1998-0809/clanek12.html

# foreign is least restrictive (no need for NEWS, AUTHORS,... files)
AUTOMAKE_OPTIONS = foreign

# extra files to be distributed
EXTRA_DIST = aclocal.m4 README.md

# library name - `.la` is used for libraries maintained with libtool
lib_LTLIBRARIES = libfooac.la
# source files of libfooac
libfooac_la_SOURCES = fooac.c
# library versioning 
libfooac_la_LDFLAGS = -version-info 1.0.0

# headers to be installed into
# ${prefix}/include, otherwise add them to  *_SOURCES
include_HEADERS = fooac.h

# executables
bin_PROGRAMS = helloac helloac.static

# source files of program helloac
helloac_SOURCES = helloac.c
# libraries used by helloac program 
helloac_LDADD = libfooac.la

# sources for helloac.static
helloac_static_SOURCES = helloac.c
# in case of using non-libtool libray use standard libxxx.a name instead
# of `.la` suffix
helloac_static_LDADD = libfooac.la
helloac_static_LDFLAGS = -static

