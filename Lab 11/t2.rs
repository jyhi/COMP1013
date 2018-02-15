use std::fmt;
use std::io::{self, Write, BufRead};

// NOTE: `str`'s length should be known at compilation, so we use String (and
// this is actually more common).
//   error[E0277]: the trait bound `str: std::marker::Sized` is not satisfied
//    --> t2.rs:4:3
//     |
//   4 |   name: str,
//     |   ^^^^^^^^^ `str` does not have a constant size known at compile-time
//     |
//     = help: the trait `std::marker::Sized` is not implemented for `str`
//     = note: only the last field of a struct may have a dynamically sized type
struct Student {
  name: String,
  major: String,
  score: u32,
}

// Formatter.
impl fmt::Display for Student {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    write!(f, "{}\t{}\t{}", self.major, self.score, self.name)
  }
}

fn main() {
  let stdin = io::stdin();

  println!("How many students to record?");
  let n: usize =
    stdin.lock().lines().next().unwrap().unwrap().parse().unwrap();

  // NOTE:
  //   1. "The vector will not allocate until elements are pushed onto it."
  //   https://doc.rust-lang.org/std/vec/struct.Vec.html#method.new
  //
  //   2. "Constructs a new, empty Vec<T> with the specified capacity. The
  //   vector will be able to hold exactly capacity elements without
  //   reallocating."
  //   https://doc.rust-lang.org/std/vec/struct.Vec.html#method.with_capacity
  let mut students: Vec<Student> = Vec::with_capacity(n);
  for i in 0..n {
    println!("----- Recording the {}th student...", i + 1);

    print!("Name: ");
    io::stdout().flush().unwrap();
    let name: String =
      stdin.lock().lines().next().unwrap().unwrap();

    print!("Score: ");
    io::stdout().flush().unwrap();
    let score: u32 =
      stdin.lock().lines().next().unwrap().unwrap().parse().unwrap();

    print!("Major: ");
    io::stdout().flush().unwrap();
    let major: String =
      stdin.lock().lines().next().unwrap().unwrap();

    students.push(Student { name: name, major: major, score: score });
  }

  println!("\n===== Now printing student info...");
  println!("Major\tScore\tName");

  for s in &students {
    println!("{}", s);
  }
}
