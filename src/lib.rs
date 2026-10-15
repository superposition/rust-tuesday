//! Facilitator reference. Learners start with `exercises/lib.rs`.

use std::collections::HashMap;

pub trait PairSearch {
    fn find(&self, nums: &[i32], target: i32) -> Option<(usize, usize)>;
}

pub struct BruteForce;
pub struct HashLookup;

impl PairSearch for BruteForce {
    fn find(&self, nums: &[i32], target: i32) -> Option<(usize, usize)> {
        // Ascending j, then i, defines a deterministic tie-break.
        for j in 0..nums.len() {
            for i in 0..j {
                if i64::from(nums[i]) + i64::from(nums[j]) == i64::from(target) {
                    return Some((i, j));
                }
            }
        }
        None
    }
}

impl PairSearch for HashLookup {
    fn find(&self, nums: &[i32], target: i32) -> Option<(usize, usize)> {
        let mut seen = HashMap::new();
        for (j, &value) in nums.iter().enumerate() {
            let needed = i64::from(target) - i64::from(value);
            // Look up before inserting: an index cannot pair with itself.
            if let Some(&i) = seen.get(&needed) {
                return Some((i, j));
            }
            // Keep the first occurrence to agree with BruteForce's tie-break.
            seen.entry(i64::from(value)).or_insert(j);
        }
        None
    }
}

// Generic bound: one concrete S per call; no trait object here.
pub fn solve<S: PairSearch>(solver: &S, nums: &[i32], target: i32) -> Option<(usize, usize)> {
    solver.find(nums, target)
}
