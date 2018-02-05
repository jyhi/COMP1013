use std::io::{stdin, BufRead};

fn main() {
  loop {
    println!("Please input a binary number:");

    // NOTE: This handle is required to live longer than its lock() method in
    // order to allow "borrowing".
    let stdin = stdin();

    let buf = match stdin.lock().lines().next() {
      Some(r) => match r {
        // NOTE: Empty string is not None.
        Ok(r) => if r.len() > 0 { r } else { return; },
        Err(e) => {
          eprintln!("Read error: {}", e);
          return;
        }
      },
      None => {
        return;
      }
    };

    let num = match u32::from_str_radix(buf.as_str(), 2) {
      Ok(r) => r,
      Err(e) => {
        eprintln!("Parse error: {}", e);
        return;
      }
    };

    println!("{:b} is {} in decimal.", num, num);
  }
}
