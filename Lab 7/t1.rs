fn main() {
    let mut array: [i32; 50] = [0; 50];

    // FIXME: If pressing Enter before 0 is typed, this program will actually boom.
    println!("Please input some numbers (input 0 to end):");
    let mut buf = String::new();
    match std::io::stdin().read_line(&mut buf) {
        Ok(_) => {},
        Err(e) => {
            println!("Read error: {}", e);
            return;
        }
    }

    let mut buf_iter = buf.split_whitespace();

    for elem in array.iter_mut() {
        *elem = match buf_iter.next() {
            Some(r) => {
                match r.parse() {
                    Ok(r) => r,
                    Err(e) => {
                        println!("Parse error: {}", e);
                        return;
                    }
                }
            },
            None => {
                // Possibly a line break before we meet a 0... Treat it as 0.
                break;
            }
        };
        if *elem == 0 {
            break;
        }
    }

    println!("Among your inputs, the following are positive:");
    for elem in array.iter() {
        if *elem > 0 {
            print!("{} ", *elem);
        }
    }
    print!("\n");
}
