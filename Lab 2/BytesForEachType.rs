use std::mem;

// Rust data types:
//
// array
// bool
// char
// f32 f64
// i8 i16 i32 i64 isize
// pointer
// slice
// str
// tuple
// u8 u16 u32 u64 usize
// i128	[Experimental] u128	[Experimental]
// -- https://doc.rust-lang.org/std/index.html#primitives

fn main() {
    // "The use keyword brings only what we’ve specified into scope: it does not bring children of
    // modules into scope."
    // -- https://doc.rust-lang.org/book/second-edition/ch07-03-importing-names-with-use.html
    println!("Number of bytes used to store a bool type is {}", mem::size_of::<bool>());
    println!("Number of bytes used to store a char type is {}", mem::size_of::<char>());
    println!("Number of bytes used to store an isize type is {}", mem::size_of::<isize>());
    println!("Number of bytes used to store a usize type is {}", mem::size_of::<usize>());
}
