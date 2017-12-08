package main

import (
  "fmt"
  "os"
  "bufio"
  "strings"
)

func main() {
  var (
    pw1, pw2 string
    buf []byte // For ReadLine use
    e error
  )

  stdin := bufio.NewReader(os.Stdin)

  for {
    // Always flush stdin before reading it.
    stdin.Discard(stdin.Buffered())

    // Round 1
    fmt.Println("Please set your password:")
    buf, _, e = stdin.ReadLine()
    if e != nil {
      fmt.Println("Read error:", e)
      return
    }

    // Length >= 8
    // NOTE: The builtin `len` will count bytes instead of runes.
    // NOTE: strings.Count returns 1 + the number of Unicode code points in s.
    // if len(buf1) < 8 {
    if strings.Count(string(buf), "") < 9 {
      fmt.Println("Password not long enough.")
      continue
    }
    pw1 = string(buf)

    // Always flush stdin before reading it.
    stdin.Discard(stdin.Buffered())

    // Round 2
    fmt.Println("Please confirm your password:")
    buf, _, e = stdin.ReadLine()
    if e != nil {
      fmt.Println("Read error:", e)
      return
    }
    pw2 = string(buf)

    // Check if two inputs match
    if pw1 != pw2 {
      fmt.Println("Passwords don't match.")
      continue
    } else {
      fmt.Println("Your password", pw1, "is confirmed.")
      break
    }
  }
}
