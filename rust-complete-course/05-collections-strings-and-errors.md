# 05 - Collections, Strings, and Result-Based Errors

## Collections

```rust
let mut numbers = vec![3, 1, 4];
numbers.push(1);
numbers.sort();

use std::collections::HashMap;
let mut counts = HashMap::new();
for word in "red blue red".split_whitespace() {
    *counts.entry(word).or_insert(0) += 1;
}
```

Other standard collections include `VecDeque`, `HashSet`, `BTreeMap`, and
`BinaryHeap`. Select based on required operations, ordering, and performance.

## `String` and UTF-8

Rust strings are UTF-8 bytes, so indexing by integer is not allowed:

```rust
let text = String::from("cafe");
let bytes = text.as_bytes();
let characters = text.chars().count();
println!("{:?} {characters}", bytes);
```

Use `&str` for borrowed text and `String` for owned, growable text. Use
`.chars()` for Unicode scalar values and `.graphemes()` from a suitable crate
when user-visible grapheme clusters are required.

## `Result` and the `?` operator

```rust
use std::num::ParseIntError;

fn parse_pair(input: &str) -> Result<(i32, i32), ParseIntError> {
    let mut parts = input.split(',');
    let left = parts.next().unwrap_or("").trim().parse()?;
    let right = parts.next().unwrap_or("").trim().parse()?;
    Ok((left, right))
}
```

`?` returns the error early and converts it when the error types are
compatible. Handle errors at the boundary:

```rust
fn main() -> Result<(), Box<dyn std::error::Error>> {
    let pair = parse_pair("10, 20")?;
    println!("{pair:?}");
    Ok(())
}
```

For libraries, define meaningful error types. The `thiserror` crate helps
derive them; `anyhow` is convenient for application-level context.

## Files and command-line arguments

```rust
use std::fs;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let text = fs::read_to_string("input.txt")?;
    println!("{} bytes", text.len());
    Ok(())
}
```

Use `std::env::args()` for simple arguments. For production CLIs, study
`clap`.

## Interactive project: word counter

Create a program that accepts a file path, reads the file, counts words, and
prints the ten most frequent words. Decide how to handle a missing path,
unreadable file, and invalid UTF-8. Add tests for the counting function.

Checkpoint: distinguish `Option<T>` (“might be absent”) from `Result<T, E>`
(“might fail, and here is why”).

