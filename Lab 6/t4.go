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
  var nline int
  var e error

  stdin := bufio.NewReader(os.Stdin)

  fmt.Print("How many line shall we draw? ")
  _, e = fmt.Fscanf(stdin, "%d", &nline)
  if e != nil {
    fmt.Println("Illegal input:", e)
    return 1
  }

  for row := 0; row < nline; row += 1 {
    to_print_asterisk := row * 2 + 1
    to_print_blank := (((nline - 1) * 2 + 1) - to_print_asterisk) / 2 + 1

    for i := 0; i < to_print_blank; i += 1 {
      fmt.Print(" ")
    }
    for i := 0; i < to_print_asterisk; i += 1 {
      fmt.Print("*")
    }

    fmt.Print("\n")
  }

  return 0
}
