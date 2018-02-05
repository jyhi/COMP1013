use std::io::{stdin, BufRead};

fn main() {
  println!("Please input a positive integer:");

  let stdin = stdin();
  let input: usize = match stdin.lock().lines().next() {
    Some(r) => match r {
      Ok(r) => match r.parse() {
        Ok(r) => r,
        Err(e) => {
          eprintln!("Parse error: {}", e);
          return;
        }
      },
      Err(e) => {
        eprintln!("Read error: {}", e);
        return;
      }
    },
    None => { return; }
  };

  println!("T({})={}", input, t(input));
}

fn t(n: usize) -> usize {
  if n == 1 {
    return 1;
  }
  return t(n / 2) + n;
}
