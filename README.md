# Helloac (Hello, Autoconf) example project

Simple project with library using old libtool automake and autoconf.


Tested (intentionally) under `Debian 6.0.6/i386`

# Basic concepts

To understand autoconf properly one need to know that there
are actually **two** source distributions:

1. **Maintainer** source
1. **End user** source


**Maintainer** is one who develops this project and is commiting new version to repository.
Maintainer needs to have installed additionally `libtool`, `autoconf` and `automake` to
be capable to regenerate target script files (for example `configure` script) from
templates (for example `configure.in`).

**End user** is one who just wants to build binary in his Unix environment from source.
End user need just to have installed C compiler and make tool.


# Setup

Here are necessary steps to build from repository - like **maintainer**.


To prepare all build scripts from this source code issue:

```
libtoolize
aclocal
automake -a
autoconf
```

= Building sample project

These steps are  used for both **end user** and **maintainer**:

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


