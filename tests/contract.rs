use rust_tuesday::{solve, BruteForce, HashLookup};

#[test]
fn examples_and_boundaries() {
    let cases: &[(&[i32], i32, Option<(usize, usize)>)] = &[
        (&[2, 7, 11, 15], 9, Some((0, 1))),
        (&[3, 2, 4], 6, Some((1, 2))),
        (&[3, 3], 6, Some((0, 1))),
        (&[3], 6, None),
        (&[], 0, None),
        (&[1, 2, 3], 99, None),
        (&[-3, 4, 3, 90], 0, Some((0, 2))),
        (&[1, 1, 4], 5, Some((0, 2))),
        (&[1, 2, 3, 4], 5, Some((1, 2))),
        (&[i32::MIN, i32::MAX], -1, Some((0, 1))),
        (&[i32::MAX, 1], i32::MIN, None),
    ];
    for &(nums, target, expected) in cases {
        assert_eq!(solve(&BruteForce, nums, target), expected);
        assert_eq!(solve(&HashLookup, nums, target), expected);
    }
}

#[test]
fn implementations_agree_on_small_input_space() {
    // 1,365 arrays, each with 9 targets: catch tie-break and duplicate errors.
    for length in 0..=5 {
        for mut encoded in 0..4usize.pow(length) {
            let nums: Vec<i32> = (0..length)
                .map(|_| {
                    let value = (encoded % 4) as i32 - 2;
                    encoded /= 4;
                    value
                })
                .collect();
            for target in -4..=4 {
                assert_eq!(
                    solve(&BruteForce, &nums, target),
                    solve(&HashLookup, &nums, target),
                    "nums={nums:?}, target={target}"
                );
            }
        }
    }
}
