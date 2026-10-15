//! Behavioral reconstruction for the rehearsal. Both modes use a simple loop.
//! The author had seen the original source; this is not an independent blind solve.
use std::{env, process::ExitCode};

fn invalid() -> ExitCode {
    eprintln!("expected: <a|b> <target:i32> [numbers:i32 ...]");
    ExitCode::from(2)
}

fn main() -> ExitCode {
    let args: Vec<String> = env::args().skip(1).collect();
    if args.len() < 2 || !matches!(args[0].as_str(), "a" | "b") {
        return invalid();
    }
    let target = match args[1].parse::<i32>() {
        Ok(value) => i64::from(value),
        Err(_) => return invalid(),
    };
    let numbers = match args[2..]
        .iter()
        .map(|text| text.parse::<i32>())
        .collect::<Result<Vec<_>, _>>()
    {
        Ok(values) => values,
        Err(_) => return invalid(),
    };

    for (right, &b) in numbers.iter().enumerate() {
        for (left, &a) in numbers[..right].iter().enumerate() {
            if i64::from(a) + i64::from(b) == target {
                println!("{left} {right}");
                return ExitCode::SUCCESS;
            }
        }
    }
    println!("none");
    ExitCode::SUCCESS
}
