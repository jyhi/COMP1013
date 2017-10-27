fn main() {
    println!("Please input an integer between 0 to 15:");

    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    let mut recv = buf.split_whitespace();
    let i = recv.next().unwrap().parse::<u32>().unwrap();
    // println!("{} is {}{}{}{} in binary.", i, bitextr(i, 4), bitextr(i, 3), bitextr(i, 2), bitextr(i, 1));
    println!("{} is {:04b} in binary", i, i);
}

// fn bitextr(i: u32, pos: u32) -> u8 {
//     if i & (1 << (pos - 1)) != 0 {
//         1
//     } else {
//         0
//     }
// }
