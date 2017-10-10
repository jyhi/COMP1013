package main

import (
  "fmt"
  "os"
)

/* "One has to ensure that rest of the code does not call os.Exit() anywhere,
 * like flag.ExitOnError, log.Fatalf(), etc."
 * -- https://stackoverflow.com/questions/4278293/how-do-i-return-from-func-main-in-go
 *
 * See "Lab 2"/MainFunction.go
 */
func main() {
  os.Exit(task2_main())
}

func task2_main() int {
  var a, b int

  fmt.Println("Input 2 integers:")
  fmt.Scanf("%d %d", &a, &b)

  if b == 0 {
    fmt.Println("b can't be 0.")
    return 1
  }

  fmt.Printf(
    "%d+%d=%d\n" +
    "%d-%d=%d\n" +
    "%d*%d=%d\n" +
    "%d/%d=%d\n" +
    "%d%%%d=%d\n",
    a, b, a + b,
    a, b, a - b,
    a, b, a * b,
    a, b, a / b,
    a, b, a % b)

  return 0
}
