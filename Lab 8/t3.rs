use std::io::stdin;
use std::process::exit;

fn main() {
  let mut str1 = String::new();
  println!("Please input the first string:");
  match stdin().read_line(&mut str1) {
    Ok(_) => {}
    Err(e) => {
      eprintln!("Read error: {}", e);
      exit(1);
    }
  }

  let mut str2 = String::new();
  println!("Please input the second string:");
  match stdin().read_line(&mut str2) {
    Ok(_) => {}
    Err(e) => {
      eprintln!("Read error: {}", e);
      exit(1);
    }
  }

  println!("The two strings are{} the same.",
           if str1 == str2 { "" } else { " not" });
}
