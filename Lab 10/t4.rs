use std::io::{stdin, BufRead};

fn main() {
  // NOTE: This time:
  //   1. Vector cannot be constant (only Vec has binary_search)
  //   2. `let` must be within a function
  let a: Vec<i32> =
    vec![-34, -33, -21, -13, -2, 3, 4, 6, 9, 12, 21, 23, 25, 32, 42, 48, 50];

  let stdin = stdin();

  println!("Please input an integer:");
  let search: i32 = match stdin.lock().lines().next() {
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

  match a.binary_search(&search) {
    Ok(i) => {
      println!("{}'s position in the array is: {}", search, i);
    },
    Err(_) => {
      println!("{}'s not in the array", search);
    }
  };
}
