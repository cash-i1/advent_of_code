use std::fs::File;
use std::io::prelude::*;

fn main() {
    let mut file = File::open("src/input.txt").unwrap();
    let mut example_string = String::new();

    file.read_to_string(&mut example_string).unwrap().to_string();
    println!("{:?}", example_string);

    let mut calibration_values: Vec<i32> = vec![];
    let mut calibration_sum: i32 = 0;

    let mut temp_nums: Vec<i32> = vec![];
    

    for line in example_string.lines() {
        for letter in line.chars() {
            if letter.is_digit(10) {

                let letter_ascii = letter.to_ascii_lowercase();
                temp_nums.push(letter_ascii.to_string().parse::<i32>().unwrap());
            }
            
        }   

        let concatenated_number: i32 = format!("{}{}", temp_nums[0], temp_nums[temp_nums.len()-1]).parse().unwrap();
        calibration_values.push(concatenated_number);
        temp_nums.clear();

    }
    
    for value in calibration_values {
        calibration_sum += value;
    }

    println!("The sum of 'calibration values' sum: {}", calibration_sum);
    
}