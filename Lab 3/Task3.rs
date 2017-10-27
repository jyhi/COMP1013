fn main() {
    println!("Input 2 integers:");

    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    let mut recv = buf.split_whitespace();
    let a = recv.next().unwrap().parse::<i32>().unwrap();
    let b = recv.next().unwrap().parse::<i32>().unwrap();

    println!("The bigger one is {}", if a >= b {a} else {b});
}
