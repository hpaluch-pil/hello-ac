# Helloac (Hello, Autoconf) example project

Simple project with library using old libtool automake and autoconf.


Tested (intentionally) under `Debian 6.0.6/i386`

# Setup

To prepare all build scripts from this source code issue:

```
libtoolize
aclocal
automake -a
autoconf
```

= Building sample project

These steps are done for source distribution - source
archive created using `make dist`.



Example:

```
./configure --prefix=/opt/helloac-1.0
make
sudo make install
```



= Re-bootstrap

If you modify any of `configure.in`, `Makefile.am` you should
run this command sequence to refresh generated files:

```
automake; aclocal; autoconf
```


= Initial setup

This is for reference only - original project bootstrap:

= Resources

* https://www.linux.cz/noviny/1998-0809/clanek12.html


