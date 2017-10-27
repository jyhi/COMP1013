fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    let mut recv = buf.split_whitespace();
    let height = recv.next().unwrap().parse::<i32>().unwrap();
    let weight = recv.next().unwrap().parse::<i32>().unwrap();

    if (height - 105) > (weight + 20) {
        println!("You are too slim");
    } else {
        if ((weight - 10) < (height - 105)) && ((height - 105) <= (weight + 20)) {
            println!("You are fit");
        } else {
            println!("You are too fat");
        }
    }
}
