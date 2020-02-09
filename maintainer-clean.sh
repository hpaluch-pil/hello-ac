#!/bin/bash

set -ex

make maintainer-clean
rm -f maintainer-clean Makefile.in configure aclocal.m4 helloac-config.h.in
cd `dirname $0`
find ./ -type l -exec rm -- {} \;

