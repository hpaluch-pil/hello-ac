#!/bin/bash

set -ex

make maintainer-clean
rm -f Makefile.in configure aclocal.m4
cd `dirname $0`
find ./ -type l -exec rm -- {} \;

