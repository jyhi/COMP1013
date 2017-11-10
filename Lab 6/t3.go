package main

import (
  "fmt"
  "os"
  "bufio"
  "strings"
)

func main() {
  os.Exit(t3_main())
}

func t3_main() int {
  buf, e := bufio.NewReader(os.Stdin).ReadString('\n')
  if e != nil {
    fmt.Println("Read Error:", e)
    return 1
  }

  fmt.Println(strings.Count(buf, "a"))
  return 0
}
