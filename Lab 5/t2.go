package main

import "fmt"

func main() {
  var height, weight int = 0, 0

  fmt.Scanf("%d %d", &height, &weight)

  if (height - 105) > (weight + 20) {
    fmt.Println("You are too slim")
  } else if ((weight - 10) < (height - 105)) && ((height - 105) <= (weight + 20)) {
    fmt.Println("You are fit")
  } else {
    fmt.Println("You are too fat")
  }
}
