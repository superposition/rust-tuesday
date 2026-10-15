//! Copy this file to a separate learner project's src/lib.rs.
//! Keep the public API so the supplied contract tests can run.

pub trait PairSearch {
    fn find(&self, nums: &[i32], target: i32) -> Option<(usize, usize)>;
}

pub struct BruteForce;
pub struct HashLookup;

impl PairSearch for BruteForce {
    fn find(&self, _nums: &[i32], _target: i32) -> Option<(usize, usize)> {
        // Exercise 1: iterate j, then i < j. Widen values to i64 before adding.
        todo!("return the first valid pair, or None")
    }
}

impl PairSearch for HashLookup {
    fn find(&self, _nums: &[i32], _target: i32) -> Option<(usize, usize)> {
        // Exercise 2: look up the complement before storing the current value.
        todo!("keep the earliest index for each value")
    }
}

pub fn solve<S: PairSearch>(_solver: &S, _nums: &[i32], _target: i32) -> Option<(usize, usize)> {
    // Exercise 3: delegate through the trait's method.
    todo!("call find")
}
