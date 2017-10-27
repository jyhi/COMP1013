fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    let gpa_alpha = match buf.split_whitespace().next() {
        Some(r) => {
            match r.parse::<char>() {
                Ok(r) => r,
                Err(e) => {
                    // This error handler can actually be in match below.
                    println!("{:?}: Illegal GPA.", e);
                    std::process::exit(255);
                }
            }
        },
        None => {
            println!("No GPA given, exiting.");
            std::process::exit(255);
        }
    };

    println!(
        "{:.2}",
        match gpa_alpha {
            'A' | 'a' => 4.00,
            'B' | 'b' => 3.00,
            'C' | 'c' => 2.00,
            'D' | 'd' => 1.00,
            'F' | 'f' => 0.00,
            _ => {
                println!("Illegal GPA.");
                std::process::exit(255);
            }
        }
    );
}
