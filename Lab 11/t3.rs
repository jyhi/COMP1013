use std::io::{stdin, BufRead};

// Time handling is in external crate "time"... Try to avoid using it
struct Date {
  year: u32,
  month: u32,
  day: u32,
}

impl Date {
  fn day_of_week_string(&self) -> String {
    let c = self.year / 100;
    let y = self.year % 100;
    let m = if self.month < 3 { self.month + 12 } else { self.month };
    let d = self.day;

    let w = (5 * c + c / 4 + y + y / 4 + 13 * (m + 1) / 5 + d) % 7;

    match w {
      0 => "Saturday".to_string(),
      1 => "Sunday".to_string(),
      2 => "Monday".to_string(),
      3 => "Tuesday".to_string(),
      4 => "Wednesday".to_string(),
      5 => "Thursday".to_string(),
      6 => "Friday".to_string(),
      _ => {
        // Something happened.
        unreachable!();
      }
    }
  }
}

fn main() {
  let stdin = stdin();
  println!("Please input Y M D:");
  let buf = stdin.lock().lines().next().unwrap().unwrap();

  let (year, month, day);
  {
    let mut recv = buf.split_whitespace();
    year = recv.next().unwrap().parse().unwrap();
    month = recv.next().unwrap().parse().unwrap();
    day = recv.next().unwrap().parse().unwrap();
  }

  let date = Date { year: year, month: month, day: day };

  println!("{}/{}/{} is {}.", year, month, day, date.day_of_week_string());
}
