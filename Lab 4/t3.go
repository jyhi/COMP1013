package main

import "fmt"

func main() {
  var a, b int = 0, 0
  fmt.Println("Please input two integers:")
  fmt.Scanf("%d %d", &a, &b)
  fmt.Printf("Between %d and %d, %d has a greater absolute value.\n", a, b, bigger(abs(a), abs(b)))
}

func abs(a int) int {
  if a >= 0 {
    return a
  } else {
    return -a
  }
}

func bigger(a, b int) int {
  if a >= b {
    return a
  } else {
    return b
  }
}
