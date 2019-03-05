# Helloac (Hello, Autoconf) example project

Simple project with library using old libtool automake and autoconf.


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

Tested under:
* [scratchbox](http://www.scratchbox.org/) environment
  for ARM in following configuration:
  
  ```
  sb-conf show warpcomm
     Compiler: arm-linux-cs2010q1-202
     Devkits: autotools-legacy mtd python-legacy qemu svn git
     CPU-transparency: /scratchbox/devkits/qemu/bin/qemu-arm-sb

  ```  

* `Debian 6.0.6/i386` - intentionally - to have good chance that it
   will work also under above `scratchbox` (which was confirmed)

* `Debian 9.8/amd64` - to verify backward compatibility. NOTE: Please ignore
   warning:
   
   ```
   autoconf input should be named 'configure.ac', not 'configure.in'
   ```

   This is our drawback because of full backward compatibility with old Linux versions.

Both **end user** and **maintainer** need to install basic development tools:

```bash
sudo apt-get install build-essential
```

Maintainer needs to additionally install:
```bash
sudo apt-get install libtool autoconf automake 
```


Here are necessary steps to build from repository - like **maintainer**.


To prepare all build scripts from this source code issue:

```
libtoolize
aclocal
automake -a
autoconf
```

Or just run:

```bash
./maintainer-setup.sh
```

## Building sample project

For end-user: download and extract
[helloac-1.0.tar.gz][helloac-1.0.tar.gz] for example using:

```bash
mkdir ~/projects
cd ~/projects
wget https://github.com/hpaluch-pil/hello-ac/archive/helloac-1.0.tar.gz
tar xzf helloac-1.0.tar.gz
cd hello-ac-helloac-1.0
# and continue below:
```

These steps are  used for both **end user** and **maintainer**:

Example:

```
./configure --prefix=/opt/helloac-1.0
make
sudo make install
```

## Create end-user source distribution

Issue this command to create source distribution archive:

```
make dist
```

And distribute created `helloac-1.0.tar.gz` archive.
The end user than just isse `./configure` and `make` command
without need to install `libtool`, `autoconf` or `automake`.


# Re-bootstrap

If you (as maintainer) modify any of `configure.in`, `Makefile.am` you should
run this command sequence to refresh generated files:

```
automake; aclocal; autoconf
```

# Maintainer clean

To clean all files that are not needed in git repository
you can use this command:

```bash
./maintainer-clean.sh
```

WARNING!

It will work only if there is `Makefile` (that is the `./configure`
script was already run before)


# Libtool versioning

WARNING!

Libtool uses its own versioning system in form
`current:revision:age` instead of common linker `major:minor:patch`.

Please see for more information:
-  http://blog.asleson.org/index.php/2014/07/08/libtool-library-versioning-version-info-currentrevisionage/
- https://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html#Updating-version-info
- calculator: https://www.pakin.org/~scott/ltver.html

# Resources

* Author's original guide written in late 90's in college
  - https://www.linux.cz/noviny/1998-0809/clanek12.html

[helloac-1.0.tar.gz]: https://github.com/hpaluch-pil/hello-ac/archive/helloac-1.0.tar.gz
