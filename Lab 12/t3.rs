fn main() {
  let (i, j) = (1i32, 1i32);
  println!("{}", compare(&i, &j));

  let (x, y) = (1.22f32, 1.21f32);
  println!("{}", compare(&x, &y));

  let (a, b) = ("Baby", "Dragon");
  println!("{}", compare(&a, &b));
}

fn compare<T: PartialOrd>(p: &T, q: &T) -> i8 {
  // NOTE: A small differece: in C version strcmp returns differences of the
  // first different character, but here only 1, 0, or -1 is returned.
  if *p < *q {
    -1
  } else if *p > *q {
    1
  } else {
    0
  }
}
