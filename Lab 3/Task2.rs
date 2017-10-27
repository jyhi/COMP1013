fn main() {
    // let (a, b): (i32, i32);
    let mut buf = String::new();

    println!("Input 2 integers:");
    std::io::stdin().read_line(&mut buf).unwrap();

    // Oh boi, no scanf.
    let mut recv = buf.split_whitespace();
    let a = recv.next().unwrap().parse::<i32>().unwrap();
    let b = recv.next().unwrap().parse::<i32>().unwrap();

    if b == 0 {
        println!("b can't be 0.");
        // See: https://stackoverflow.com/questions/24245276/why-does-rust-not-have-a-return-value-in-the-main-function-and-how-to-return-a
        // See: Lab 2/MainFunction.rs
        std::process::exit(1);
    }

    print!(
        "{}+{}={}\n{}-{}={}\n{}*{}={}\n{}/{}={}\n{}%{}={}\n",
        a, b, a + b,
        a, b, a - b,
        a, b, a * b,
        a, b, a / b,
        a, b, a % b,
    );
}
