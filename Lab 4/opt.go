package main

import "fmt"

func main() {
  var i uint = 0
  fmt.Println("Please input an integer between 0 to 15:")
  fmt.Scanf("%d", &i)

  // // this number very 4-bit
  // i &= 0xf;

  fmt.Printf(
    "%d is %d%d%d%d in binary.\n",
    i, bitextr(i, 4), bitextr(i, 3), bitextr(i, 2), bitextr(i, 1))
}

func bitextr(n, bit uint) uint {
  if n & (1 << (bit - 1)) != 0 {
    return 1
  } else {
    return 0
  }
}
