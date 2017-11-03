package main

import (
  "fmt"
  "os"
  "bufio"
  "unsafe"
)

func main() {
  var n int
  var result uint = 1
  var i int   // Tmp Counter
  var e error // Ret Error

  stdin := bufio.NewReader(os.Stdin)

  _, e = fmt.Fscanf(stdin, "%d", &n)
  if e != nil {
    fmt.Println("Illegal input: ", e)
    return
  }
  if n < 0 {
    fmt.Println("Meet negative number, expect positive one. Exiting.")
    return
  }
  if uintptr(n) >= (unsafe.Sizeof(uint) * 8) {
    fmt.Printf("Warning: N larger than or equal to %d may cause unpredictable output.\n", unsafe.Sizeof(uint) * 8)
  }

  // Using while per requirement
  // i = n
  // for i != 0 {
  //   result *= 2
  //   i -= 1
  // }

  // There is no do-while in Go.

  // Using for per requirement.
  for i = n; i != 0; i -= 1 {
    result *= 2
  }

// output:
  fmt.Printf("2^%d is %d\n", n, result)

  stdin.Discard(stdin.Buffered())
}
