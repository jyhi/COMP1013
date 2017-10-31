package main

import (
  "fmt"
  "os"
  "bufio"
)

func main() {
  var mycard, guess = 3, 0
  stdin := bufio.NewReader(os.Stdin)
  var e error

  for {
    fmt.Print("Guess my card: ")
    _, e = fmt.Fscanf(stdin, "%d", &guess)
    if e != nil {
      fmt.Println("Input error:", e)
      return
    }

    if guess == mycard {
      fmt.Println("Good guess!")
      // break

      // Avoid using break per requirement.
      // os.Exit(0)
      goto quit
    } else {
      fmt.Println("Try again.")
      // NOTE: If the buffer is not cleared, next fmt.Fscanf will yield an error
      // "unexpected newline".
      stdin.Discard(stdin.Buffered())
    }
  }

quit:
}
