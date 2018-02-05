use std::io::{stdin, BufRead};

fn main() {
  println!("Please input a decimal number:");
  let stdin = stdin();
  let num: usize = match stdin.lock().lines().next() {
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

  println!("{:b}", num);
}
