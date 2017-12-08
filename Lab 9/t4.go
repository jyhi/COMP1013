package main

import (
  "fmt"
  "os"
  "bufio"
  "strings"
)

func main() {
  var (
    buf []byte // For ReadLine use
    e error
  )

  stdin := bufio.NewReader(os.Stdin)

  fmt.Println("Please input the first string:")
  buf, _, e = stdin.ReadLine()
  if e != nil {
    fmt.Println("Read error:", e)
    return
  }
  str1 := string(buf)

  stdin.Discard(stdin.Buffered())

  fmt.Println("Please input the second string:")
  buf, _, e = stdin.ReadLine()
  if e != nil {
    fmt.Println("Read error:", e)
    return
  }
  str2 := string(buf)

  if strings.Contains(str2, str1) {
    fmt.Println("The first string is a substring of the second.")
  } else {
    fmt.Println("The first string is not a substring of the second.")
  }
}
