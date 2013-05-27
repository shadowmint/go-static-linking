package bridge

import "fmt"

// #cgo CFLAGS: -I/Users/douglasl/projects/go/go-static-linking/include
// #cgo LDFLAGS: /Users/douglasl/projects/go/go-static-linking/build/libgb.a
// #include <junk.h>
import "C"

func Run() {
  fmt.Printf("Invoking c library...\n")
  C.x(10)
  fmt.Printf("Done\n")
}
