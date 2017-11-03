fn main() {
    for i in 0..10 {
        for _ in 0..(i + 1) {
            print!("* ");
        }
        print!("\n");
    }
}
