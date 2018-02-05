package main

import (
  "fmt"
  "os"
  "bufio"
  "strings"
  "strconv"
)

func main() {
  fmt.Println("Please input a decimal number:")
  line, e := bufio.NewReader(os.Stdin).ReadString('\n')
  if e != nil {
    fmt.Fprintln(os.Stderr, "Read error:", e)
    return
  }
  line = strings.TrimSuffix(line, "\n")

  num, e := strconv.ParseInt(line, 10, 0)
  if e != nil {
    fmt.Fprintln(os.Stderr, "Convert error:", e)
    return
  }

  fmt.Printf("%b\n", num)
}
