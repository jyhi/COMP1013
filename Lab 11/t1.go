package main

import (
  "fmt"
  "math"
)

type point struct {
  x, y int
}

type line struct {
  p1, p2 point
}

type triangle struct {
  p1, p2, p3 point
}

/* Methods for point */

// func (p point) print() {
//   fmt.Printf("Point: (%d, %d)\n", p.x, p.y)
// }

/**
 * "Formatter is the interface implemented by values with a custom formatter.
 * The implementation of Format may call Sprint(f) or Fprint(f) etc. to generate
 * its output."
 *   -- https://golang.org/pkg/fmt/#Formatter
 */
func (p point) Format(f fmt.State, c rune) {
  // NOTE: Theoretically I should implement different style of formatters but
  // here I just cannot be bordered.
  if _, e := f.Write([]byte(fmt.Sprintf("Point: (%d, %d)", p.x, p.y))); e != nil {
    f.Write([]byte(fmt.Sprintf("!%%%cPoint!", c)))
  }
}

/* Methods for line */

func (l line) length() float64 {
  // NOTE: point has member x, y as int
  delta_x := math.Abs(float64(l.p1.x - l.p2.x))
  delta_y := math.Abs(float64(l.p1.y - l.p2.y))

  return math.Sqrt(math.Pow(delta_x, 2) + math.Pow(delta_y, 2))
}

// func (l line) print() {
//   fmt.Printf("Line: (%d, %d) - (%d, %d) Length = %f\n",
//     l.p1.x, l.p1.y, l.p2.x, l.p2.y,
//     l.length())
// }

func (l line) Format(f fmt.State, c rune) {
  output := []byte(fmt.Sprintf("Line: (%d, %d) - (%d, %d) Length = %f",
    l.p1.x, l.p1.y, l.p2.x, l.p2.y, l.length()))

  if _, e := f.Write(output); e != nil {
    f.Write([]byte(fmt.Sprintf("!%%%cLine!", c)))
  }
}

/* Methods for triangle */

func (t triangle) circumference() float64 {
  lines := [3]line{line{t.p1, t.p2}, line{t.p2, t.p3}, line{t.p3, t.p1}}

  return lines[0].length() + lines[1].length() + lines[2].length()
}

// func (t triangle) print() {
//   fmt.Printf("Triangle: (%d, %d) - (%d, %d) - (%d, %d) Circumference: %f\n",
//     t.p1.x, t.p1.y,
//     t.p2.x, t.p2.y,
//     t.p3.x, t.p3.y,
//     t.circumference())
// }

func (t triangle) Format(f fmt.State, c rune) {
  output := []byte(fmt.Sprintf(
    "Triangle: (%d, %d) - (%d, %d) - (%d, %d) Circumference: %f",
    t.p1.x, t.p1.y, t.p2.x, t.p2.y, t.p3.x, t.p3.y, t.circumference()))

  if _, e := f.Write(output); e != nil {
    f.Write([]byte(fmt.Sprintf("!%%%cTriangle!", c)))
  }
}

func main() {
  // Per requirement.
  p := [6]point{
    point{1, 5}, point{2, 1}, point{2, 7},
    point{4, 3}, point{6, 8}, point{8, 2}}
  l := [4]line{
    line{p[0], p[2]}, line{p[3], p[4]},
    line{p[3], p[5]}, line{p[4], p[5]}}
  t := triangle{p[3], p[4], p[5]}

  for _, point := range p {
    // point.print()
    fmt.Println(point)
  }
  for _, line := range l {
    // line.print()
    fmt.Println(line)
  }
  // t.print()
  fmt.Println(t)
}
