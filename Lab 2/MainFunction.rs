use std::process; // Not using this will generate "warning: unused import: `std::process`

/* NOTE: There is no way to return anything directly in main().
 * To achieve this, use std::process::exit(); however it terminates the process, no destructors on
 * the current stack or any other thread's stack will be run.
 *
 * A conventional way to use the function is to extract the actual computation to another function
 * and compute the exit code from its return value.
 *
 * See: https://doc.rust-lang.org/std/process/fn.exit.html
 */

fn main() {
    println!("Hello");
    // process::exit(0); // This will generate "warning: unreachable statement"
    println!("World");
    process::exit(0);
    // process::exit(1);
}
