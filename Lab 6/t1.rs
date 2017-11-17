fn main() {
    println!("Please input a positive integer:");
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    let input = buf.split_whitespace().next().unwrap().parse::<i32>().unwrap();

    if input <= 0 {
        println!("Meet negative number or 0, expect positive one. Exiting.");
        std::process::exit(1);
    }

    for i in 2..input {
        if input % i == 0 {
            println!("{} is not a prime", input);
            return
        }
    }

    println!("{} is a prime.", input);
}
