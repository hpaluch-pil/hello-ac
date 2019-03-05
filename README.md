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

These steps are  used for build from "source distribution" (see next chapter).

Example:

```
./configure --prefix=/opt/helloac-1.0
make
sudo make install
```

= Create end-user source distribution

Issue this command to create source distribution archive:

```
make dist
```

And distribute created `helloac-1.0.tar.gz` archive.
The end user than just isse `./configure` and `make` command
without need to install `libtool`, `autoconf` or `automake`.


= Re-bootstrap

If you modify any of `configure.in`, `Makefile.am` you should
run this command sequence to refresh generated files:

```
automake; aclocal; autoconf
```


= Resources

* https://www.linux.cz/noviny/1998-0809/clanek12.html


