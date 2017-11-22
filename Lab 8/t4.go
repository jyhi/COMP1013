package main

import (
  "fmt"
  "os"
  "bufio"
  "unicode"
)

func main() {
  var input string
  var e error

  stdin := bufio.NewReader(os.Stdin)

  _, e = fmt.Fscanf(stdin, "%s", &input)
  if e != nil {
    fmt.Println("Invalid input:", e)
    return
  }

  for _, k := range []rune(input) {
    if !unicode.IsDigit(k) {
      break
    }
    fmt.Print(string(k))
  }
  fmt.Println()
}
