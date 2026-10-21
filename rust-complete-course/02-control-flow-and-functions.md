# 02 - Control Flow, Functions, and Expressions

## Functions

Rust requires parameter and return types:

```rust
fn rectangle_area(width: u32, height: u32) -> u32 {
    width * height
}

fn main() {
    let area = rectangle_area(8, 3);
    println!("area = {area}");
}
```

The final expression has no semicolon and becomes the return value. `return`
is useful for an early exit:

```rust
fn absolute_difference(a: i32, b: i32) -> i32 {
    if a >= b { a - b } else { b - a }
}
```

## `if`, loops, and ranges

`if` is an expression, so both branches must have compatible types:

```rust
let temperature = 24;
let message = if temperature > 30 { "hot" } else { "comfortable" };
```

```rust
for number in 1..=5 {
    println!("{number}");
}

let mut attempts = 0;
let result = loop {
    attempts += 1;
    if attempts == 3 {
        break attempts * 10;
    }
};
println!("result = {result}");
```

`while` repeats while a condition is true. `loop` repeats forever until
`break`. Loops can be labeled when nested:

```rust
'outer: for row in 0..3 {
    for column in 0..3 {
        if row == 1 && column == 1 {
            break 'outer;
        }
    }
}
```

## `match`

`match` must be exhaustive:

```rust
fn describe(number: i32) -> &'static str {
    match number {
        0 => "zero",
        1..=9 => "single digit",
        n if n < 0 => "negative",
        _ => "other",
    }
}
```

The `_` pattern means “anything else”. Patterns can destructure tuples and
other values.

## Interactive challenge

Write `is_prime(n: u32) -> bool` without using external crates. Predict what
should happen for `0`, `1`, `2`, `3`, `9`, and `97`, then add tests:

```rust
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn prime_cases() {
        assert!(!is_prime(1));
        assert!(is_prime(2));
        assert!(is_prime(97));
        assert!(!is_prime(100));
    }
}
```

## Exercises

1. Implement `fizz_buzz(n: u32) -> String`.
2. Implement `sum_even(numbers: &[i32]) -> i32`.
3. Rewrite one `for` loop as a `while` loop.
4. Add tests for boundary values and run `cargo test`.

Checkpoint: you should know when a value is an expression, how `break` can
return a value, and why `match` needs every case covered.

