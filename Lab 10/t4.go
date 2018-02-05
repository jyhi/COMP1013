package main

import (
  "fmt"
  "os"
  "bufio"
  "sort"
)

// Umm, slice can't be constant...
var a = []int{-34, -33, -21, -13, -2, 3, 4, 6, 9, 12, 21, 23, 25, 32, 42, 48, 50}

func main() {
  var (
    search int
    e error
  )

  stdio := bufio.NewReader(os.Stdin)

  fmt.Println("Please input an integer:")
  _, e = fmt.Fscanf(stdio, "%d", &search)
  if e != nil {
    fmt.Fprintln(os.Stderr, "Invalid input:", e)
    return
  }

  if i := sort.SearchInts(a, search); a[i] == search {
    fmt.Printf("%d's position in the array is: %d\n", search, i)
  } else {
    fmt.Printf("%d's not in the array\n", search)
  }
}
