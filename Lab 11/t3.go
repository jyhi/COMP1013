package main

import (
  "fmt"
  "os"
  "bufio"
  "time"
)

func main() {
  var (
    year, month, day int
    buf string
    e error
  )

  fmt.Println("Please input Y M D:")
  buf, e = bufio.NewReader(os.Stdin).ReadString('\n')
  if e != nil {
    fmt.Fprintln(os.Stderr, "Read error:", e)
    return
  }
  _, e = fmt.Sscanf(buf, "%d %d %d", &year, &month, &day)
  if e != nil {
    fmt.Fprintln(os.Stderr, "Parse error:", e)
    return
  }

  // type Month int, January Month = 1 + iota
  // https://golang.org/pkg/time/#Month
  // XXX: Conversion of month does not consider border
  fmt.Printf("%d/%d/%d is %s.\n",
    year, month, day,
    time.Date(year, time.Month(month), day, 0, 0, 0, 0, time.Local).Weekday().String())
}
