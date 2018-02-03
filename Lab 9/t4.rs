use std::io::stdin;
use std::process::exit;

fn main() {
  println!("Please input the first string:");
  let mut str1 = String::new();
  match stdin().read_line(&mut str1) {
    Ok(_) => {},
    Err(e) => {
      eprintln!("Read error: {}", e);
      exit(1);
    }
  }
  // Strip newline, then shadow it (becoming immutable)
  let str1 = str1.trim_right();

  println!("Please input the second string:");
  let mut str2 = String::new();
  match stdin().read_line(&mut str2) {
    Ok(_) => {},
    Err(e) => {
      eprintln!("Read error: {}", e);
      exit(1);
    }
  }
  // Strip newline, then shadow it (becoming immutable)
  let str2 = str2.trim_right();

  println!("The first string is{} a substring of the second.",
           if str2.contains(str1) { "" } else { " not" });
}
