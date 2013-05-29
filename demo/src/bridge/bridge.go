package bridge

import "fmt"

// #cgo CFLAGS: -I/Users/doug/projects/go/go-static-linking/include
// #cgo LDFLAGS: /Users/doug/projects/go/go-static-linking/build/libgb.a /Users/doug/projects/go/go-static-linking/build/python/lib/libpython2.7.a
// #include <junk.h>
import "C"

func Run() {
  fmt.Printf("Invoking c library...\n")
  C.x(0)
  fmt.Printf("Done\n")
}
