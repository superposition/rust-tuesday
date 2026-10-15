use std::process::Command;

#[test]
fn command_line_contract() {
    for mode in ["a", "b"] {
        for (args, expected) in [
            (vec![mode, "9", "2", "7", "11", "15"], "0 1\n"),
            (vec![mode, "6", "3", "3"], "0 1\n"),
            (vec![mode, "6", "3"], "none\n"),
            (vec![mode, "0"], "none\n"),
        ] {
            let output = Command::new(env!("CARGO_BIN_EXE_pair-finder"))
                .args(args)
                .output()
                .unwrap();
            assert!(output.status.success());
            assert_eq!(String::from_utf8(output.stdout).unwrap(), expected);
            assert!(output.stderr.is_empty());
        }
    }
    for args in [
        vec![],
        vec!["c", "9"],
        vec!["a"],
        vec!["b", "9", "x"],
        vec!["a", "2147483648"],
    ] {
        let output = Command::new(env!("CARGO_BIN_EXE_pair-finder"))
            .args(args)
            .output()
            .unwrap();
        assert_eq!(output.status.code(), Some(2));
        assert!(output.stdout.is_empty());
        assert!(!output.stderr.is_empty());
    }
}
