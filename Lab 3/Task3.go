package main

import "fmt"

func main() {
  var a, b int

  fmt.Println("Input 2 integers:")
  fmt.Scanf("%d %d", &a, &b)
  // NOTE: There is no ternary testing (?:) operation in Go.
  // -- https://golang.org/doc/faq#Does_Go_have_a_ternary_form
  fmt.Printf("The bigger one is %d\n", bigger(a, b))
}

func bigger(a, b int) int {
  if a >= b {
    return a
  } else {
    return b
  }
}
