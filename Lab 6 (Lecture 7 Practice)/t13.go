package main

import "fmt"

func main() {
  var sum, i int = 0, 1

  for ; i <= 100; i += 1 {
    // if i % 2 == 0 {
    //   continue
    // }
    // sum = sum + i

    // Avoid using continue per requirement.
    if i % 2 != 0 {
      sum = sum + i
    }
  }

  fmt.Printf("i = %d, sum = %d\n", i, sum)
}
