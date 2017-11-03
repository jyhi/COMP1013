use std::io::Write;

fn main() {
    let mycard = 3;
    // let mut guess = 0;
    let mut bufin = String::new();

    loop {
        print!("Guess my card: ");
        // NOTE that stdout is frequently line-buffered by default so it may be necessary to use
        // io::stdout().flush() to ensure the output is emitted immediately.
        // (See https://doc.rust-lang.org/std/macro.print.html)
        // NOTE: fn flush() is in trait std::io::Write (need to use it explicitly).
        std::io::stdout().flush().unwrap();

        // NOTE: "[read_line] Read all bytes until a newline (the 0xA byte) is reached, and append
        // them to the provided buffer."
        // (See: https://doc.rust-lang.org/stable/std/io/trait.BufRead.html#method.read_line)
        //
        // Before reading, always clear the buffer...
        bufin.clear();
        std::io::stdin().read_line(&mut bufin).unwrap();
        let guess: i32 = bufin.split_whitespace().next().unwrap().parse().unwrap(); // Shadowing

        if guess == mycard {
            println!("Good guess!");
            break;
        } else {
            println!("Try again.");
        }
    }
}
