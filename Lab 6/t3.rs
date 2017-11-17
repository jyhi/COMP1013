fn main() {
    let mut buf = String::new();
    match std::io::stdin().read_line(&mut buf) {
        Ok(_) => {},
        Err(e) => {
            println!("Error while reading: {}", e);
            std::process::exit(1);
        }
    };

    let mut counter:i32 = 0;
    for i in buf.chars() {
        if i == 'a' {
            counter += 1;
        }
    }

    println!("{}", counter);
}
