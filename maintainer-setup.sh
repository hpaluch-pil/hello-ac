#!/bin/bash

set -ex

libtoolize
aclocal
automake -a
autoconf
exit 0

