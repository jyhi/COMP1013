package main

import (
  "fmt"
  "os"
  "bufio"
  "strings"
  "strconv"
)

func main() {
  os.Exit(t1_main())
}

func t1_main() int {
  for {
    fmt.Println("Please input a binary number:")
    line, e := bufio.NewReader(os.Stdin).ReadString('\n')
    if e != nil {
      fmt.Fprintln(os.Stderr, "Read error:", e)
      return 1
    }
    // NOTE: ParseInt will refuse to convert a string with any illegal
    // characters.
    line = strings.TrimSuffix(line, "\n")

    num, e := strconv.ParseInt(line, 2, 0)
    if e != nil {
      fmt.Fprintln(os.Stderr, "Convert error:", e)
      return 1
    }

    fmt.Printf("%b is %d in decimal.\n", num, num)
  }
}
