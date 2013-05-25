package bridge

import "fmt"

// #cgo CFLAGS: -I/Users/doug/projects/c/go-bridge2/include
// #cgo LDFLAGS: /Users/doug/projects/c/go-bridge2/build/libgb.a
// #include <junk.h>
import "C"

func Run() {
  fmt.Printf("Invoking c library...\n")
  C.x(10)
  fmt.Printf("Done\n")
}
