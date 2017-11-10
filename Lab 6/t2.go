package main

import (
  "fmt"
  "os"
  "bufio"
)

func main() {
  var input int
  var e error

  stdin := bufio.NewReader(os.Stdin)

  for {
    stdin.Discard(stdin.Buffered())
    fmt.Print("Please input a positive integer (input 0 to exit): ")
    _, e = fmt.Fscanf(stdin, "%d", &input)
    if e != nil {
      fmt.Println("Illegal input")
      stdin.Discard(stdin.Buffered())
      continue
    }

    if input == 0 {
      return
    }

    if is_prime(input) == true {
      fmt.Println(input, "is a prime.");
    } else {
      fmt.Println(input, "is not a prime.")
    }
  }
}

func is_prime(input int) bool {
  if input <= 0 {
    fmt.Println("** Meet nagative number or 0, expect positive one.")
    return false
  }

  for i := 2; i < input; i += 1 {
    if input % i == 0 {
      return false
    }
  }

  return true
}
