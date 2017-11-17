use std::io::Write;

fn main() {
    print!("How many line shall we draw? ");
    std::io::stdout().flush().unwrap();
    let mut buf = String::new();
    match std::io::stdin().read_line(&mut buf) {
        Ok(_) => {},
        Err(e) => {
            println!("Read error: {}", e);
            std::process::exit(1);
        }
    };

    let nline = match buf.split_whitespace().next() {
        Some(r) => {
            match r.parse::<i32>() {
                Ok(r) => r,
                Err(e) => {
                    println!("Parse error: {}", e);
                    std::process::exit(1);
                }
            }
        },
        None => {
            println!("No input is given... Exiting.");
            return;
        }
    };

    for row in 0..nline {
        let to_print_asterisk = row * 2 + 1;
        let to_print_blank = (((nline - 1) * 2 + 1) - to_print_asterisk) / 2 + 1;

        for _ in 0..to_print_blank {
            print!(" ");
        }
        for _ in 0..to_print_asterisk {
            print!("*");
        }
        println!("");
    }
}
