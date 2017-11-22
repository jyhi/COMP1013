package main

import (
  "fmt"
  "os"
  "bufio"
)

func main() {
  os.Exit(t1_main())
}

func t1_main() int {
  var a [50]int
  var count int
  var e error

  fmt.Println("Please input some numbers (input 0 to end):")
  stdin := bufio.NewReader(os.Stdin)
  for count = 0; count < 50; count += 1 {
    _, e = fmt.Fscanf(stdin, "%d", &a[count])
    if e != nil {
      fmt.Println("Illegal input detected, exiting.")
      return 1
    }
    if a[count] == 0 {
      break
    }
  }

  fmt.Println("Among your inputs, the following are positive:")
  for i := 0; i < count; i += 1 {
    if a[i] > 0 {
      fmt.Print(a[i], " ")
    }
  }
  fmt.Print("\n")

  return 0
}
