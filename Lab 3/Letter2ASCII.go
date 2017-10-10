package main

import "fmt"

func main() {
  // NOTE: There's no "char" type in Go. Instead, "rune" (uint32, representing
  // a Unicode character).
  var c rune

  fmt.Println("Please input an English letter:")
  fmt.Scanf("%c", &c)
  fmt.Printf(
    "\"%c\" and its neighbors in ASCII:\n" +
    "%d\t%d\t%d\n" +
    "%c\t%c\t%c\n",
    c,
    c - 1, c, c + 1,
    c - 1, c, c + 1)
}
