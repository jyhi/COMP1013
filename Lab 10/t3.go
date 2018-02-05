package main

import (
  "fmt"
  "os"
  "bufio"
)

func main() {
  var (
    input int
    e error
  )

  stdio := bufio.NewReader(os.Stdin)

  fmt.Println("Please input a positive integer:")
  _, e = fmt.Fscanf(stdio, "%d", &input)
  if e != nil {
    fmt.Fprintln(os.Stderr, "Illegal input:", e)
    return
  }

  fmt.Printf("T(%d)=%d\n", input, t(input))
}

func t(n int) int {
  if n == 1 {
    return 1
  }
  return t(n/2) + n
}
