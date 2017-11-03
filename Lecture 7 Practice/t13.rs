fn main() {
    let mut sum: i32 = 0;

    for i in 1..101 { // [1, 101)
        if i % 2 == 0 {
            continue;
        }
        sum = sum + i;
    }

    // TODO: Display i
    println!("sum = {}", sum);
}
