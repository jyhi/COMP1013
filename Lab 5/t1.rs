fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    let mut recv = buf.split_whitespace();
    let mut n = recv.next().unwrap().parse::<i32>().unwrap();

    if n < 0 {
        n = -n
    };

    n = n + n;

    println!("{}", n);
}
