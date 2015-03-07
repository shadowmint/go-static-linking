package bridge

import "fmt"

// #cgo CFLAGS: -IC:/projects/go-static-linking/include
// #cgo LDFLAGS: C:/projects/go-static-linking/build/libgb.a
// #include <junk.h>
import "C"

func Run() {
  fmt.Printf("Invoking c library...\n")
  C.x(10)
  fmt.Printf("Done\n")
}
