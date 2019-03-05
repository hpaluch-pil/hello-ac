# Makefile.am - project helloac (Hello Autoconf)
# Inspired by my own article: https://www.linux.cz/noviny/1998-0809/clanek12.html

# foreign is least restrictive (no need for NEWS, AUTHORS,... files)
AUTOMAKE_OPTIONS = foreign

# hint from libtoolize
ACLOCAL_AMFLAGS = -I m4

# extra files to be distributed
EXTRA_DIST = aclocal.m4 README.md .gitignore

# library name - `.la` is used for libraries maintained with libtool
lib_LTLIBRARIES = libfooac.la
# source files of libfooac
libfooac_la_SOURCES = fooac.c

# WARNING! This is obscure setting:
#          According to:
#          -  http://blog.asleson.org/index.php/2014/07/08/libtool-library-versioning-version-info-currentrevisionage/
#          - https://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html#Updating-version-info
#          - https://www.pakin.org/~scott/ltver.html
#
# standard linux versioning: 'major:minor:patch'
# libtool versioning:        'current:revision:age' -> 'c:r:a'
#                             condition: ' a <= c '
#
# There are 3 scenarios:
#
# 1. full compatibility retained (comparable to 'patch' level increase): 
#    Outcome: 'c:r:a' => 'c:r+1:a'
#
# 2. backward compatibility (comparable to 'minor' level increase):
#    Outcome: 'c:r:a' => 'c+1:0:a+1'
#
# 3. incompatible change (comparable to 'major' level increase):
#    Outcome: 'c:r:a' => 'c+1:0:0'
#
libfooac_la_LDFLAGS = -version-info 0:0:0

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

