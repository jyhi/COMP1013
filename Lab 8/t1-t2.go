package main

import (
  "fmt"
  "os"
)

func main() {
  os.Exit(t1_main())
}

func t1_main() int {
  value := []float32{2.5, -4.75, 1.2, 3.67}
  var bigValue, lowValue float32

  bigValue = findBiggest (value)
  lowValue = findLowest (value)
  fmt.Printf("bigValue = %f, lowValue = %f\n", bigValue, lowValue)
  return 0
}

func findBiggest(a []float32) float32 {
  var biggest float32

  for _, k := range a {
    if k > biggest {
      biggest = k
    }
  }

  return biggest
}

func findLowest(a []float32) float32 {
  var lowest float32

  for _, k := range a {
    if k > lowest {
      lowest = k
    }
  }

  return lowest
}
