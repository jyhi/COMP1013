fn main() {
    let mut result: usize = 1;

    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    let mut recv = buf.split_whitespace();
    let n: isize = recv.next().unwrap().parse::<isize>().unwrap();
    if n < 0 {
        println!("Meet negative number, expect positive one. Exiting.");
        return;
    }
    if n >= (std::mem::size_of::<usize>() * 8) as isize {
        // NOTE: No, actually Rust will panic:
        // > $ ./t3-t6-t8
        // > 64
        // > Warning: N larger than or equal to 64 may cause unpredictable output.
        // > thread 'main' panicked at 'attempt to multiply with overflow', t3-t6-t8.rs:19:9
        // > note: Run with `RUST_BACKTRACE=1` for a backtrace.
        println!("Warning: N larger than or equal to {} may cause unpredictable output.", std::mem::size_of::<usize>() * 8);
    }

    // Using while per requirement.
    // let mut i = n;
    // while i != 0 {
    //     result *= 2;
    //     i -= 1;
    // }

    // do-while: no such thing.

    // Using for per requirement.
    for _ in 0..n {
        result *= 2;
    }

    println!("2^{} is {}", n, result);
}
