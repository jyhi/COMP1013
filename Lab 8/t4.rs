use std::io::stdin;
use std::process::exit;

fn main() {
  let mut buf = String::new();
  match stdin().read_line(&mut buf) {
    Ok(_) => {}
    Err(e) => {
      eprintln!("Read error: {}", e);
      exit(1);
    }
  }

  for i in buf.chars() {
    if !i.is_digit(10) {
      break;
    }
    print!("{}", i);
  }
  println!("");
}
