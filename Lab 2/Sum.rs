fn main() {
    // NOTE: In this case rustc will prompt "warning: variable does not need to be mutable".
    // let (mut value1, mut value2, mut sum): (i32, i32, i32);
    let (mut value1, mut value2, mut sum): (f32, f32, f32);

    // NOTE: No implicit type convention is allowed.
    // value1 = 50;
    // value2 = 25;
    value1 = 50.0;
    value2 = 25.0;
    sum = value1 + value2;
    // print!("The sum of {} and {} is {}\n", value1, value2, sum);
    print!("The sum of {:.1} and {} is {}\n", value1, value2, sum); // The sum of 50.0 and 25 is 75
}
