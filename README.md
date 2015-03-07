# Go-C static linked demo

Quick demo to show how to statically link a c library to a go application.

## Quick start

    mkdir build
    cd build
    cmake ..
    make

    cd ..
    cd demo
    export GOPATH=`pwd`
    go build
    ./demo

## Windows

Building and running on windows is complicated. Long story short, do this:

    mkdir build
    cd build
    cmake .. -G "MSYS Makefiles"
    make

    cd ..
    cd demo
    export GOPATH=`pwd`
    go build
    ./demo

### Windows notes

You must use MSYS for cgo. Visual studio is not supported.
Install MSYS and run the MSYS shell for the commands.

You must *also* use the *right* MSYS. The default MSYS is usually
32-bit; the default windows install of go is 64-bit. That won't work.
Either install the 64-bit version of MSYS, or the 32-bit version of
go.

You have to use the MSYS shell. Using the standard shell, or powershell
won't work; the right commands are not the PATH and `go build` won't
work.

Once again, no, visual studio is not supported. If you run:

    cmake ..

The default is to generate a visual studio projet. Don't use this,
the static .lib file generated is not compatible.
using the 32-bit version of go.

Finally, yes, it does actually work. :)

![yay](https://raw.github.com/shadowmint/go-static-linking/master/media/win32.png)
