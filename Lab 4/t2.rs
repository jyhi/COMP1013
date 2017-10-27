fn main() {
    println!("Please input three integers:");

    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    let mut recv = buf.split_whitespace();
    let a = recv.next().unwrap().parse::<i32>().unwrap();
    let b = recv.next().unwrap().parse::<i32>().unwrap();
    let c = recv.next().unwrap().parse::<i32>().unwrap();

    println!(
        "Among {}, {} and {}, {} is the greatest.",
        a, b, c,
        if a > c {
            if a > b {
                a
            } else {
                b
            }
        } else {
            if b > c {
                b
            } else {
                c
            }
        }
    );
}
