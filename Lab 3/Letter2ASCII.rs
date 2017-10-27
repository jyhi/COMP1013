fn main() {
    let mut buf = String::new();

    println!("Please input an English letter:");
    std::io::stdin().read_line(&mut buf).unwrap(); // -> Result<usize>

    let c = buf.chars().next().unwrap(); // -> Option<char>
    let c_cp = c as u8; // Cast to retrive a UTF-8 Code Point
                        // Only u8 can be casted into char again; so in this case I do not care
                        // Unicode characters.

    print!(
        // In Rust you can even concatenate strings
        "\"{}\" and its neighbors in ASCII:\n{}\t{}\t{}\n{}\t{}\t{}\n",
        c_cp,
        (c_cp - 1) as char, c as char, (c_cp + 1) as char,
        c_cp - 1, c_cp, c_cp + 1
    );
}
