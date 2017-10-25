package main

import "fmt"

func main() {
  var n int = 0
  fmt.Scanf("%d", &n)

  if n < 0 {
    n = -n
  }

  n = n + n

  fmt.Printf("%d\n", n)
}
