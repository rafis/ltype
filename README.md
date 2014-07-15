ltype
=====

Faster type() function made by storing typenames in closure upvalues.

Installation
============

I prefer to user versioned luarocks:

    git clone https://github.com/keplerproject/luarocks.git

    ./configure --lua-version=5.1 --versioned-rocks-dir
    make build
    sudo make install

    ./configure --lua-version=5.2 --versioned-rocks-dir
    make build
    sudo make install

Now we can install `ltype`:

    git clone https://github.com/rafis/ltype.git
    cd ltype
    sudo luarocks-5.1 install rockspec/ltype-1.0-1.rockspec
    sudo luarocks-5.2 install rockspec/ltype-1.0-1.rockspec

Usage
=====

When you `require("ltype")` the `type()` function in global namespace will be replaced with closured version.

    require("ltype")

    assert(type("abc") == "string")


