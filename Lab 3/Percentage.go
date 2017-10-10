package main

import "fmt"

func main() {
  var percentage, x int
  var ch1, ch2 rune
  fmt.Scanf("%d%c%c%d", &percentage, &ch1, &ch2, &x)
  // NOTE: "Unlike in C, in Go assignment between items of different type
  // requires an explicit conversion." -- https://tour.golang.org/basics/13
  // fmt.Printf("%d%% %c%c %d is %f\n", percentage, ch1, ch2, x, 1.0 * x * percentage / 100)
  fmt.Printf("%d%% %c%c %d is %f\n", percentage, ch1, ch2, x, float32(x * percentage / 100))
}
