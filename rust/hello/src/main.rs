#![warn(clippy::all, clippy::pedantic)]
use std::io::stdin;

fn get_user_name() -> String {

    let mut name = String::new();

    stdin()
        .read_line(&mut name)
        .expect("Failed to read name");
    name
    
}


fn sum_numbers() -> i32 {

    let mut nums = String::new();

    stdin()
        .read_line(&mut nums)
        .expect("Failed to read number");

        nums.trim().parse().expect("Por favor ingresa un número válido")


}


fn main() {

    println!("Hello, what's your name?");

    let username = get_user_name();
    
    println!("Hello, {username}");

    println!("Give me a first number:");

    let num1 = sum_numbers();

    println!("Give me a second number:");

    let num2 = sum_numbers();

    println!("Sum: {}", num1 + num2);
 
} 
