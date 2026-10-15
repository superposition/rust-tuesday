use rust_tuesday::{solve, BruteForce, HashLookup};
use std::{env, process::ExitCode};

const USAGE: &str = "usage: pair-finder <a|b> <target:i32> [numbers:i32 ...]";

struct Request {
    mode: String,
    target: i32,
    nums: Vec<i32>,
}

impl Request {
    // Associated function: creates a Request; it has no self parameter.
    fn parse(mut args: impl Iterator<Item = String>) -> Result<Self, String> {
        let mode = args.next().ok_or_else(|| USAGE.to_owned())?;
        if mode != "a" && mode != "b" {
            return Err(USAGE.to_owned());
        }
        let target = args.next().ok_or_else(|| USAGE.to_owned())?;
        let target = parse_number(&target)?;
        let nums = args
            .map(|arg| parse_number(&arg))
            .collect::<Result<_, _>>()?;
        Ok(Self { mode, target, nums })
    }

    // Inherent method: borrows a Request to run the selected strategy.
    fn run(&self) -> Option<(usize, usize)> {
        match self.mode.as_str() {
            "a" => solve(&BruteForce, &self.nums, self.target),
            "b" => solve(&HashLookup, &self.nums, self.target),
            _ => unreachable!("Request::parse validated the mode"),
        }
    }
}

// Free function: no impl block and no self parameter.
fn parse_number(text: &str) -> Result<i32, String> {
    text.parse().map_err(|_| format!("invalid i32: {text}"))
}

fn main() -> ExitCode {
    let request = match Request::parse(env::args().skip(1)) {
        Ok(request) => request,
        Err(message) => {
            eprintln!("{message}");
            return ExitCode::from(2);
        }
    };
    match request.run() {
        Some((i, j)) => println!("{i} {j}"),
        None => println!("none"),
    }
    ExitCode::SUCCESS
}
