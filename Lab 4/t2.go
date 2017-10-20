package main

import "fmt"

func main() {
  var a, b, c int = 0, 0 ,0
  fmt.Println("Please input three integers:")
  fmt.Scanf("%d %d %d", &a, &b, &c)
  fmt.Printf("Among %d, %d and %d, %d is the greatest.\n", a, b, c, tri_bigger(a, b, c))
}

func tri_bigger(a, b, c int) int {
  if a > c {
    if a > b {
      return a
    } else {
      return b
    }
  } else {
    if b > c {
      return b
    } else {
      return c
    }
  }
}
