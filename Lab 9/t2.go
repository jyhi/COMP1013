package main

import (
  "fmt"
  "os"
  "bufio"
  "strings"
)

func main() {
  fmt.Println("Please input a line:")
  line, e := bufio.NewReader(os.Stdin).ReadString('\n')
  if e != nil {
    fmt.Println("Read error:", e)
    return
  }

  fmt.Println("The first word is:", strings.Fields(line)[0])
}
