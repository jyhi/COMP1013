package main

import (
  "fmt"
  "os"
  "bufio"
)

func main() {
  os.Exit(t4_main())
}

func t4_main() int {
  var matrix_a, matrix_b [4]int
  var e error

  stdin := bufio.NewReader(os.Stdin)

  fmt.Println("Please input matrix 1 (2*2):")

  // "When ranging over a slice, two values are returned for each iteration. The
  // first is the index, and the second is a copy of the element at that index."
  // -- https://tour.golang.org/moretypes/16

  for i, _ := range matrix_a {
    _, e = fmt.Fscanf(stdin, "%d", &matrix_a[i])
    if e != nil {
      fmt.Println("Read error:", e)
      return 1
    }
  }

  // Read error: unexpected newline
  stdin.Discard(stdin.Buffered())

  fmt.Println("Please input matrix 2 (2*2):")
  for i, _ := range matrix_b {
    _, e = fmt.Fscanf(stdin, "%d", &matrix_b[i])
    if e != nil {
      fmt.Println("Read error:", e)
      return 1
    }
  }

  fmt.Printf(
    "The SUM matrix is:\n%d\t%d\n%d\t%d\n",
    matrix_a[0] + matrix_b[0], matrix_a[1] + matrix_b[1],
    matrix_a[2] + matrix_b[2], matrix_a[3] + matrix_b[3])

  return 0
}
