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
  var input int
  var e error

  stdin := bufio.NewReader(os.Stdin)
  _, e = fmt.Fscanf(stdin, "%d", &input)
  if e != nil {
    fmt.Println("Illegal input:", e)
    return 1
  }

  if input <= 0 {
    fmt.Println("Meet negative number or 0, expect positive one. Exiting.")
    return 1
  }

  for i := 2; i < input; i += 1 {
    if input % i == 0 {
      fmt.Println(input, "is not a prime.")
      return 0
    }
  }

  fmt.Println(input, "is a prime.")
  return 0
}
