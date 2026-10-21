# 01 - Start Here: Rust, Cargo, and Your First Program

## What you will learn

- What Rust is good at: performance, memory safety, and reliable tooling.
- How to install Rust with `rustup`.
- How to create, run, format, lint, test, and build a Cargo project.
- Variables, mutability, constants, shadowing, comments, and basic types.
- How to learn interactively: predict the output, run the command, then explain why.

## Install and verify

Install Rust from <https://www.rust-lang.org/tools/install>. On macOS/Linux:

```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
source "$HOME/.cargo/env"
rustc --version
cargo --version
rustup update
```

Useful commands:

```bash
cargo new rust-playground
cd rust-playground
cargo run
cargo check
cargo fmt
cargo clippy
cargo test
cargo build
cargo build --release
```

`cargo check` is the fastest compile check. `cargo run` compiles and runs. Use
`cargo fmt` and `cargo clippy` regularly.

## First program

Create `src/main.rs`:

```rust
fn main() {
    let name = "Rust learner";
    println!("Hello, {name}!");
    println!("2 + 3 = {}", 2 + 3);
}
```

Run it with `cargo run`. The `main` function is the executable entry point.
`println!` is a macro, identified by `!`.

## Variables and types

```rust
const MAX_SCORE: u32 = 100;

fn main() {
    let age: u8 = 20;
    let mut score = 10_i32;
    score += 5;

    let score = score * 2; // shadowing: a new variable named score
    let ratio: f64 = score as f64 / MAX_SCORE as f64;

    println!("{age} {score} {ratio:.2}");
}
```

Common scalar types: `bool`, `char`, signed integers (`i8` through `i128`),
unsigned integers (`u8` through `u128`), `f32`, `f64`, and `usize`.
Compound types are tuples and arrays:

```rust
let point: (i32, i32) = (3, 4);
let first = point.0;
let days = [31, 28, 31, 30];
println!("{first} {}", days[0]);
```

## Interactive checkpoint

Before running, predict the output:

```rust
fn main() {
    let x = 5;
    let x = x + 1;
    {
        let x = x * 2;
        println!("inner: {x}");
    }
    println!("outer: {x}");
}
```

Then change `let x = 5` to `let mut x = 5` and try `x += 1` instead of
shadowing. Which version creates a new binding?

## Exercises

1. Create a program that converts Celsius to Fahrenheit.
2. Create an array of five scores and print the first and last score.
3. Run `cargo fmt`, `cargo check`, `cargo clippy`, and `cargo test`.

Checkpoint: you should be able to explain the difference between `let mut`,
shadowing, `const`, and a type cast.

