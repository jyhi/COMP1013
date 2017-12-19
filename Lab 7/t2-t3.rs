fn main() {
    println!("Please input a lower-case English word:");
    let mut buf = String::new();
    match std::io::stdin().read_line(&mut buf) {
        Ok(_) => {},
        Err(e) => {
            println!("Read error: {}", e);
            return;
        }
    };

    // read_line includes a '\n' in buf. Purge it.
    buf.pop();

    println!("It's {} palindrome.", if is_palindrome(buf) == true {"a"} else {"not a"});
}

fn is_palindrome(s: String) -> bool {
    let s = s.as_bytes();
    let length = s.len();
    for p in 0..(length / 2) {
        if s[p] != s[length - 1 - p] {
            return false;
        }
    }

    true
}
