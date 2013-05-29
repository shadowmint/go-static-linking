package bridge

import "C"
import "fmt"

//export MyFunc
func MyFunc(x int) {
  fmt.Printf("GO: Got an incoming call with value %d!\n", x)
}
