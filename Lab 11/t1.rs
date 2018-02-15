extern crate core;

use core::fmt;

#[derive(Copy, Clone)]
struct Point {
  x: i32,
  y: i32,
}

#[derive(Copy, Clone)]
struct Line {
  p1: Point,
  p2: Point,
}

#[derive(Copy, Clone)]
struct Triangle {
  p1: Point,
  p2: Point,
  p3: Point,
}

impl fmt::Display for Point {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    // Here I just ignore all flags from the format string.
    write!(f, "Point: ({}, {})", self.x, self.y)
  }
}

impl Line {
  fn length(&self) -> f64 {
    // NOTE: point has member x, y as i32
    let delta_x = (self.p1.x - self.p2.x).abs();
    let delta_y = (self.p1.y - self.p2.y).abs();

    ((delta_x.pow(2) + delta_y.pow(2)) as f64).sqrt()
  }
}

impl fmt::Display for Line {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    write!(
      f, "Line: ({}, {}) - ({}, {}) Length = {:.6}", // Just like in C
      self.p1.x, self.p1.y, self.p2.x, self.p2.y, self.length()
    )
  }
}

impl Triangle {
  fn circumference(&self) -> f64 {
    // NOTE: This statement can only be used when traits Copy and Clone are
    // implemented for both Line and Point (in this case we use #derive, see
    // code above), since if not this `<key>: <value>` assignment will be of
    // move semantics:
    //
    //   error[E0507]: cannot move out of borrowed content
    //     --> t1.rs:65:18
    //      |
    //   65 |       Line { p1: self.p1, p2: self.p2 },
    //      |                  ^^^^ cannot move out of borrowed content
    //
    //   <...>
    //
    //  error: aborting due to 6 previous errors
    let lines = [
      Line { p1: self.p1, p2: self.p2 },
      Line { p1: self.p2, p2: self.p3 },
      Line { p1: self.p3, p2: self.p1 },
    ];

    lines[0].length() + lines[1].length() + lines[2].length()
  }
}

impl fmt::Display for Triangle {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    write!(
      f, "Triangle: ({}, {}) - ({}, {}) - ({}, {}) Circumference: {:.6}",
      self.p1.x, self.p1.y, self.p2.x, self.p2.y, self.p3.x, self.p3.y,
      self.circumference()
    )
  }
}

fn main() {
  // Per requirement.
  let p = [
    Point { x: 1, y: 5}, Point { x: 2, y: 1}, Point { x: 2, y: 7},
    Point { x: 4, y: 3}, Point { x: 6, y: 8}, Point { x: 8, y: 2},
  ];

  // NOTE: "You cannot use the [expr; N] initialisation syntax for non-Copy
  // types because of Rust’s ownership model..."
  //   -- https://stackoverflow.com/questions/27393166/how-do-i-initialize-an-array-of-vectors/27393386#27393386
  // let l = [
  //   Line { p1: Point { x: 1, y: 5}, p2: Point { x: 2, y: 7} },
  //   Line { p1: Point { x: 4, y: 3}, p2: Point { x: 6, y: 8} },
  //   Line { p1: Point { x: 4, y: 3}, p2: Point { x: 8, y: 2} },
  //   Line { p1: Point { x: 6, y: 8}, p2: Point { x: 8, y: 2} },
  // ];
  // let t = Triangle {
  //   p1: Point { x: 4, y: 3},
  //   p2: Point { x: 6, y: 8},
  //   p3: Point { x: 8, y: 2},
  // };

  // NOTE: Since we used #[derive(Copy, Clone)] for all types to allow copy
  // instead of move semantics, we can directly assign points.
  let l = [
    Line { p1: p[0], p2: p[2] }, Line { p1: p[3], p2: p[4] },
    Line { p1: p[3], p2: p[5] }, Line { p1: p[4], p2: p[5] },
  ];
  let t = Triangle { p1: p[3], p2: p[4], p3: p[5] };

  // For arrays with 32 or fewer elements, &array can be used as an iterator.
  for point in &p {
    println!("{}", point);
  }
  for line in &l {
    println!("{}", line);
  }
  println!("{}", &t);
}
