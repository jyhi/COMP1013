// warning: constant `...` should have an upper case name such as ...
const XRATE_US2_EUR: f64 = 0.5;
const XRATE_US2_RMB: f64 = 7.0;

fn main() {
    println!("Please input the amount of US dollars");
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    let usd = match buf.split_whitespace().next() {
        Some(r) => {
            match r.parse::<f64>() {
                Ok(r) => r,
                Err(e) => {
                    println!("{:?}: Illegal number of US dollars.", e);
                    std::process::exit(255);
                }
            }
        },
        None => {
            // Nothing from stdin
            println!("No input... Exiting.");
            std::process::exit(255);
        }
    };

    println!("Convert to Euro(E) or RMB(R)?");
    buf.clear();
    std::io::stdin().read_line(&mut buf).unwrap();
    let selection = match buf.split_whitespace().next() {
        Some(r) => {
            match r.parse::<char>() {
                Ok(r) => r,
                Err(e) => {
                    // FIXME: Inputing multiple characters (e.g. "RE") will result in
                    // "ParseCharError { kind: TooManyChars }: Illegal type of conversion."
                    println!("{:?}: Illegal type of conversion.", e);
                    std::process::exit(255);
                }
            }
        },
        None => {
            println!("No input... Exiting.");
            std::process::exit(255);
        }
    };

    let result = match selection {
        'E' | 'e' => usd * XRATE_US2_EUR,
        'R' | 'r' => usd * XRATE_US2_RMB,
        _ => {
            // Not EUR nor RMB
            println!("Wrong type of conversion, exiting.");
            std::process::exit(1);
        }
    };

    println!(
        "{} US dollars converts to {} {}",
        usd, result, match selection {
            'E' | 'e' => "euro",
            'R' | 'r' => "yuan",
            _ => "that much"
        }
    );
}
