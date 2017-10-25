package main

import (
  "fmt"
  "os"
)

const XRate_US2EUR float64 = 0.5
const XRate_US2RMB float64 = 7.0

func main() {
  os.Exit(t3_main())
}

func t3_main() int {
  var usd, result float64 = 0, 0
  var selection rune = 0
  var err error

  fmt.Println("Please input the amount of US dollars:")
  _, err = fmt.Scanf("%f", &usd)
  if err != nil {
    fmt.Println(err, ": Illegal number of US dollars.")
    return 255
  }

  // this stdin very dirty
  // but how to clean it?

  fmt.Println("Convert to Euro(E) or RMB(R)?")
  _, err = fmt.Scanf("%c", &selection)
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
  // Should flush it right before we return (and exit). But how (elegantly)?

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
