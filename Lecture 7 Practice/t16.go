package main

import "fmt"

func main() {
  for i := 0; i < 10; i += 1 {
    for j:= 0; j <= i; j += 1 {
      fmt.Print("* ")
    }
    fmt.Println()
  }
}
