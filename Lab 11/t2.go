package main

import (
  "fmt"
  "os"
  "bufio"
  "strings"
)

type student struct {
  name, major string
  score int
}

// This is not elegant, but I try to use it.
func (s student) Format(f fmt.State, c rune) {
  f.Write([]byte(fmt.Sprintf("%s\t%d\t%s", s.major, s.score, s.name)))
}

func main() {
  var (
    n int      // Number of students
    buf string // Buffer of line read from stdin
    e error
  )

  stdin := bufio.NewReader(os.Stdin)

  fmt.Println("How many students to record?")
  buf, e = stdin.ReadString('\n')
  if e != nil {
    fmt.Fprintln(os.Stderr, "Invalid input:", e)
    return
  }
  _, e = fmt.Sscanf(buf, "%d", &n)
  if e != nil {
    fmt.Fprintln(os.Stderr, "Invalid input:", e)
    return
  }

  if n <= 0 {
    fmt.Fprintln(os.Stderr, "Invalid number of student... exiting.")
    return
  }

  students := make([]student, n)
  for i := 0; i < n; i++ {
    fmt.Printf("----- Recording the %dth student...\n", i + 1)

    fmt.Print("Name: ")
    students[i].name, e = stdin.ReadString('\n')
    if e != nil {
      fmt.Fprintln(os.Stderr, "Read error:", e)
      return
    }
    students[i].name = strings.TrimSuffix(students[i].name, "\n")

    fmt.Print("Score: ")
    buf, e = stdin.ReadString('\n')
    if e != nil {
      fmt.Fprintln(os.Stderr, "Read error:", e)
      return
    }
    _, e = fmt.Sscanf(buf, "%d", &students[i].score)
    if e != nil {
      fmt.Fprintln(os.Stderr, "Parse error:", e)
      return
    }

    fmt.Print("Major: ")
    students[i].major, e = stdin.ReadString('\n')
    if e != nil {
      fmt.Fprintln(os.Stderr, "Read error:", e)
      return
    }
    students[i].major = strings.TrimSuffix(students[i].major, "\n")
  }

  fmt.Println("\n===== Now printing student info...")
  fmt.Println("Major\tScore\tName")

  for _, s := range students {
    fmt.Println(s)
  }
}
