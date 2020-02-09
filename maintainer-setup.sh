#!/bin/bash

set -ex

libtoolize
aclocal
autoheader
automake -a
autoconf
exit 0

