package main

import "fmt"

func main() {
  var a, b int = 0, 0
  fmt.Println("Please input two integers:")
  fmt.Scanf("%d %d", &a, &b)
  fmt.Printf("Between %d and %d, %d is greater.\n", a, b, bigger (a, b))
}

func bigger(a, b int) int {
  if a >= b {
    return a
  } else {
    return b
  }
}
