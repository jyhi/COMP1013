fn main() {
    println!("Please input matrix 1 (2*2):");
    let mut buf = String::new();
    match std::io::stdin().read_line(&mut buf) {
        Ok(_) => {},
        Err(e) => {
            println!("Read error: {}", e);
            return;
        }
    };

    let mut matrix_a: [i32; 4] = [0; 4];
    {
        // NOTE: Limit the lifetime of buf_iter...
        // error[E0502]: cannot borrow `buf` as mutable because it is also borrowed as immutable
        //   --> t4.rs:33:5
        //    |
        // 12 |     let mut buf_iter = buf.split_whitespace();
        //    |                        --- immutable borrow occurs here
        // ...
        // 33 |     buf.clear();
        //    |     ^^^ mutable borrow occurs here
        // ...
        // 63 | }
        //    | - immutable borrow ends here
        //
        // See https://stackoverflow.com/questions/47618823/cannot-borrow-as-mutable-because-it-is-also-borrowed-as-immutable:
        // "You are encountering the exact problem that Rust was designed to prevent... you cannot
        // have a mutable reference while there are other references to the same thing."

        let mut buf_iter = buf.split_whitespace();

        for i in matrix_a.iter_mut() {
            *i = match buf_iter.next() {
                Some(r) => {
                    match r.parse() {
                        Ok(r) => r,
                        Err(e) => {
                            println!("Parsing error: {}", e);
                            return;
                        }
                    }
                },
                None => {
                    break;
                }
            }
        }
    }

    println!("Please input matrix 2 (2*2):");
    buf.clear();
    match std::io::stdin().read_line(&mut buf) {
        Ok(_) => {},
        Err(e) => {
            println!("Read error: {}", e);
            return;
        }
    };

    let mut matrix_b: [i32; 4] = [0; 4];
    {
        let mut buf_iter = buf.split_whitespace();

        for i in matrix_b.iter_mut() {
            *i = match buf_iter.next() {
                Some(r) => {
                    match r.parse() {
                        Ok(r) => r,
                        Err(e) => {
                            println!("Parsing error: {}", e);
                            return
                        }
                    }
                },
                None => {
                    break;
                }
            }
        }
    }

    println!(
        "The SUM matrix is:\n{}\t{}\n{}\t{}",
        matrix_a[0] + matrix_b[0], matrix_a[1] + matrix_b[1],
        matrix_a[2] + matrix_b[2], matrix_a[3] + matrix_b[3]
    );
}
