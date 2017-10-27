package main

import (
  "fmt"
  "os"
  "bufio"
)

func main() {
  var gpa_alpha rune = 0
  var stdin *bufio.Reader = bufio.NewReader(os.Stdin)

  fmt.Fscanf(stdin, "%c", &gpa_alpha)

  switch gpa_alpha {
  case 'A':
    fallthrough
  case 'a':
    fmt.Printf("%.2f\n", 4.00)
  case 'B':
    fallthrough
  case 'b':
    fmt.Printf("%.2f\n", 3.00)
  case 'C':
    fallthrough
  case 'c':
    fmt.Printf("%.2f", 2.00)
  case 'D':
    fallthrough
  case 'd':
    fmt.Printf("%.2f\n", 1.00)
  case 'F':
    fallthrough
  case 'f':
    fmt.Printf("%.2f\n", 0.00)
  default:
    fmt.Println("Illegal GPA.")
  }

  stdin.Discard(stdin.Buffered())
}
