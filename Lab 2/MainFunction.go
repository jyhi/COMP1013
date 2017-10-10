package main

// NOTE: If you don't use anything in a package, you will get an ERROR.
// ./MainFunction.go:5:5: error: imported and not used: os
//    "os"
//      ^

import (
  "fmt"
  "os"
)

/* NOTE: There is no way to return anything directly in main().
 * To achieve this, use os.Exit(); however it terminates the program immediately
 * and does not run deferreed functions (See: https://golang.org/pkg/os/#Exit)
 *
 * "One has to ensure that rest of the code does not call os.Exit() anywhere,
 * like flag.ExitOnError, log.Fatalf(), etc."
 * -- https://stackoverflow.com/questions/4278293/how-do-i-return-from-func-main-in-go
 */

func main() {
  fmt.Println ("Hello")
  // os.Exit(0)
  fmt.Println ("World")
  os.Exit(0)
  // os.Exit(1)
}
