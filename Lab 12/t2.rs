use std::io::{stdin, BufRead};
use std::fmt;

struct Student {
  name: String,
  id: i32,
  gpa: f32,
}

impl fmt::Display for Student {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    write!(f, "{}\t{}\t{}", self.name, self.id, self.gpa)
  }
}

fn main() {
  let mut students: Vec<Student> = Vec::new();
  let stdin = stdin();

  loop {
    println!("Please input record #{} (Name, ID, GPA):", students.len() + 1);

    let line = stdin.lock().lines().next().unwrap().unwrap();

    let mut line_split = line.split_whitespace();

    let name     = String::from(line_split.next().unwrap());
    let id:  i32 = line_split.next().unwrap().parse().unwrap();
    let gpa: f32 = line_split.next().unwrap().parse().unwrap();

    if name == "0" && id == 0i32 && gpa == 0f32 {
      break;
    }

    if !check_id(&students, &id) {
      eprintln!("Error: Student ID already exists.");
      continue;
    }

    if !check_gpa(&gpa) {
      eprintln!("Error: Invalid GPA.");
      continue;
    }

    students.push(Student { name: name, id: id, gpa: gpa });
  }

  for i in students.iter() {
    println!("{}", i);
  }
}

fn check_id(students: &Vec<Student>, id: &i32) -> bool {
  for stu in students.iter() {
    if stu.id == *id {
      return false
    }
  }

  true
}

fn check_gpa(gpa: &f32) -> bool {
  if *gpa <= 0f32 || *gpa > 4f32 {
    false
  } else {
    true
  }
}
