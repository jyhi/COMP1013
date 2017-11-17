fn main() {
    let mut buf = String::new();
    loop {
        println!("Please input a positive integer (input 0 to exit)");
        buf.clear();
        std::io::stdin().read_line(&mut buf).unwrap();
        let input = match buf.split_whitespace().next() {
            Some(r) => {
                match r.parse::<i32>() {
                    Ok(r) => r,
                    Err(e) => {
                        println!("Invalid input: {}", e);
                        continue;
                    }
                }
            },
            None => {
                println!("No input is given...");
                continue;
            }
        };

        if input == 0 {
            return;
        }

        println!("{} {} a prime", input, if is_prime (input) == true {"is"} else {"is not"});
    }
}

fn is_prime(n: i32) -> bool {
    if n <= 0 {
        println!("** Meet negative number or 0, expect positive one.");
        return false;
    }

    for i in 2..n {
        if n % i == 0 {
            return false;
        }
    }

    return true;
}
