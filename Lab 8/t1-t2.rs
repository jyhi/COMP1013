fn main() {
  let value: Vec<f32> = vec![2.5, -4.75, 1.2, 3.67];

  // I need to read more about this "borrowing" problem...
  let big_value = find_biggest(&value);
  let low_value = find_lowest(&value);

  println!("bigValue = {}, lowValue = {}", big_value, low_value);
}

fn find_biggest(arr: &Vec<f32>) -> f32 {
  let mut biggest: f32 = 0.0;

  for i in arr.iter() {
    if i > &biggest {
      biggest = *i;
    }
  }

  biggest
}

fn find_lowest(arr: &Vec<f32>) -> f32 {
  let mut lowest: f32 = 0.0;

  for i in arr.iter() {
    if i < &lowest {
      lowest = *i;
    }
  }

  lowest
}
