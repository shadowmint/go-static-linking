## Go-C static linked demo

Quick demo to show how to statically link a c library to a go application.

### Quick start

    mkdir build
    cd build
    cmake ..
    make

    cd ..
    cd demo
    export GOPATH=`pwd`
    go build
    ./demo
