package main

import (
  "fmt"
  "os"
  "bufio"
  "strings"
)

func main() {
  os.Exit(t2_main())
}

func t2_main() int {
  var buf string
  var e error

  stdin := bufio.NewReader(os.Stdin)

  fmt.Println("Please input a lower-case English word")
  _, e = fmt.Fscanf(stdin, "%s", &buf)
  if e != nil {
    fmt.Println("Read error:", e)
    return 1
  }

  // if is_palindrome(buf) == true {
  if is_palindrome(strings.ToLower(buf)) == true { // t3
    fmt.Println("It's a palindrome.")
  } else {
    fmt.Println("It's not a palindrome.")
  }

  return 0
}

func is_palindrome(str string) bool {
  length := strings.Count(str, "") - 1

  for p := 0; p < length / 2; p += 1 {
    if str[p] != str[length - 1 - p] {
      return false
    }
  }

  return true
}
