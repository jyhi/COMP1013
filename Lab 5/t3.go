package main

import (
  "fmt"
  "os"
  "bufio"
)

const XRate_US2EUR float64 = 0.5
const XRate_US2RMB float64 = 7.0

func main() {
  os.Exit(t3_main())
}

// NOTE: None of Stdin, Stdout or Stderr are buffered. See:
// http://grokbase.com/t/gg/golang-nuts/158cgb3rfd/go-nuts-os-stdout-is-not-buffered:
//
// > In C, printf, fprintf functions write to a FILE *stream, and "stdout" is a
// > "stream", not a file.
// >
// > In Go, fmt.Print, fmt.Fprintf functions write directly to a file, not a
// > Writer (equivalent to a C "stream").
// >
// > It is just that the "stdout" word means different things in C and Go ...
//
// This means, to achieve the same behavior as C's buffered "streams", we must
// by hand create an I/O buffer.

func t3_main() int {
  var usd, result float64 = 0, 0
  var selection rune = 0
  var err error

  // In this case we only create a buffer for Stdin.
  var stdin *bufio.Reader = bufio.NewReader(os.Stdin);

  fmt.Println("Please input the amount of US dollars:")
  // _, err = fmt.Scanf("%f", &usd)
  _, err = fmt.Fscanf(stdin, "%f", &usd)
  if err != nil {
    fmt.Println(err, ": Illegal number of US dollars.")
    return 255
  }

  // this stdin very dirty
  _, _ = stdin.Discard(stdin.Buffered())

  fmt.Println("Convert to Euro(E) or RMB(R)?")
  // _, err = fmt.Scanf("%c", &selection)
  _, err = fmt.Fscanf(stdin, "%c", &selection)
  if err != nil {
    fmt.Println(err, ": Illegal type of conversion.")
    return 255
  }

  switch selection {
  case 'E':
    fallthrough
  case 'e':
    result = usd * XRate_US2EUR
  case 'R':
    fallthrough
  case 'r':
    result = usd * XRate_US2RMB
  default:
    // Not EUR nor RMB
    fmt.Println("Wrong type of conversion, exiting.")
    return 1
  }

  fmt.Printf("%g US dollars converts to %g %s.\n", usd, result, currency_name(selection))

  // NOTE: Golang's os.Exit does NOT even flush stdin.
  // Should flush it right before we return (and exit).
  _, _ = stdin.Discard(stdin.Buffered())

  return 0
}

func currency_name(sel rune) string {
  switch sel {
  case 'E':
    fallthrough
  case 'e':
    return "euro"
  case 'R':
    fallthrough
  case 'r':
    return "yuan"
  default:
    return "that much"
  }
}
