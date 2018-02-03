use std::io::{stdin, BufRead};
use std::process::exit;

fn main() {
  loop {
    println!("Please set your password:");

    // NOTE: To read a line without the newline character, there are two ways:
    //   1. First read a whole line, and then trim whitespaces at right
    //   2. Lock stdin, gain BufRead::lines() iterator, and get the first item
    //      (which is the first line)
    //
    // See documentation of BufRead::lines():
    //   "Each string returned will not have a newline byte (the 0xA byte) or
    //   CRLF (0xD, 0xA bytes) at the end."
    //   https://doc.rust-lang.org/std/io/trait.BufRead.html#method.lines

    // NOTE: 1st method
    // let mut pwd_set = String::new();
    // match stdin().read_line(&mut pwd_set) {
    //   Ok(_) => {}
    //   Err(e) => {
    //     eprintln!("Read error: {}", e);
    //     exit(1);
    //   }
    // }
    //
    // // Strip newline, then shadow it (becoming immutable)
    // // NOTE: Now pwd_set is &str (not String)!
    // let pwd_set = pwd_set.trim_right();

    // NOTE: 2nd method
    // NOTE: This stdin handler should be visible through the two assignment
    // procedures.
    //
    // error[E0597]: `stdin` does not live long enough
    //   --> t3.rs:33:5
    //    |
    // 21 |       let lock = stdin.lock();
    //    |                  ----- borrow occurs here
    // ...
    // 33 |     };
    //    |     ^- borrowed value needs to live until here
    //    |     |
    //    |     `stdin` dropped here while still borrowed
    let stdin = stdin();

    let pwd_set = {
      let lock = stdin.lock();

      // NOTE: lines().next() returns Option<Result<String>>. See:
      //   https://doc.rust-lang.org/std/io/struct.Lines.html#method.next
      match lock.lines().next() {
        Some(r) => match r {
          Ok(r) => r,
          Err(e) => {
            eprintln!("Read error: {}", e);
            exit(1);
          }
        }
        None => String::from("")
      }
    };

    // Length >= 8
    if pwd_set.len() < 8 {
      println!("Password not long enough.");
      continue;
    }

    println!("Please confirm your password:");

    // NOTE: 1st method
    // let mut pwd_confirmed = String::new();
    // match stdin().read_line(&mut pwd_confirmed) {
    //   Ok(_) => {}
    //   Err(e) => {
    //     eprintln!("Read error: {}", e);
    //     exit(1);
    //   }
    // }
    //
    // // Strip newline, then shadow it (becoming immutable)
    // let pwd_confirmed = pwd_confirmed.trim_right();

    // NOTE: 2nd method
    let pwd_confirmed = {
      let lock = stdin.lock();

      match lock.lines().next() {
        Some(r) => match r {
          Ok(r) => r,
          Err(e) => {
            eprintln!("Read error: {}", e);
            exit(1);
          }
        }
        None => String::from("")
      }
    };

    if pwd_set != pwd_confirmed {
      println!("Passwords don't match.");
      continue;
    } else {
      println!("Your password {} is confirmed.", pwd_set);
      break;
    }
  }
}
