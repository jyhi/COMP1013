package main

import "fmt"

func main() {
  // var value1, value2, sum int
  var value1, value2, sum float32
  value1 = 50
  value2 = 25
  sum = value1 + value2
  // fmt.Printf("The sum of %d and %d is %d\n", value1, value2, sum)
  // fmt.Printf("The sum of %f and %f is %f\n", value1, value2, sum)
  fmt.Printf("The sum of %.1f and %f is %f\n", value1, value2, sum)
}
