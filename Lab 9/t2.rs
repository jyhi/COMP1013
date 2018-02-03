fn main() {
  println!("Please input a line:");

  let mut buf = String::new();
  match std::io::stdin().read_line(&mut buf) {
    Ok(_) => {}
    Err(e) => {
      eprintln!("Read error: {}", e);
      std::process::exit(1);
    }
  }

  println!("The first word is: {}",
           buf.split_whitespace().next().unwrap_or(""));
}
