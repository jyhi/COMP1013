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
  var str1, str2 string
  var e error

  stdin := bufio.NewReader(os.Stdin)

  fmt.Println("Please input the first string:")
  _, e = fmt.Fscanf(stdin, "%s", &str1)
  if e != nil {
    fmt.Println("Read Error:", e)
    return 1
  }

  stdin.Discard(stdin.Buffered())

  fmt.Println("Please input the second string:")
  _, e = fmt.Fscanf(stdin, "%s", &str2)
  if e != nil {
    fmt.Println("Read Error:", e)
    return 1
  }

  // "Compare... is usually clearer and always faster to use the built-in string
  // comparison operators ==, <, >, and so on."
  // -- https://golang.org/pkg/strings/#Compare
  // if str1 == str2 {
  if strings.Compare(str1, str2) == 0 {
    fmt.Println("The two strings are the same.")
  } else {
    fmt.Println("The two strings are not the same.")
  }

  return 0
}
