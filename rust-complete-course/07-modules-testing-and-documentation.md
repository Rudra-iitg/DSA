# 07 - Modules, Crates, Workspaces, Tests, and Documentation

## Project structure

```text
my-app/
├── Cargo.toml
├── src/
│   ├── main.rs
│   ├── lib.rs
│   └── parser.rs
└── tests/
    └── integration_test.rs
```

`src/main.rs` is a binary crate. `src/lib.rs` is a library crate. A package
can contain both. Keep modules focused:

```rust
// src/lib.rs
pub mod parser;

pub fn public_api() {}
```

```rust
// src/parser.rs
pub fn parse(input: &str) -> Vec<&str> {
    input.split_whitespace().collect()
}
```

`pub` controls visibility. Child modules can access private items in their
parent, while users outside the module need a public path.

## Tests

Unit tests usually live beside the code:

```rust
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn parser_splits_words() {
        assert_eq!(crate::parser::parse("a b"), ["a", "b"]);
    }
}
```

Integration tests live in `tests/` and use the public API:

```rust
use my_app::parser;

#[test]
fn public_parser_works() {
    assert_eq!(parser::parse("one two").len(), 2);
}
```

Run focused tests with `cargo test parser`, show output with
`cargo test -- --nocapture`, and check documentation examples with
`cargo test --doc`.

## Documentation and dependencies

Use `///` for public API documentation:

```rust
/// Returns the number of non-empty words.
pub fn word_count(text: &str) -> usize {
    text.split_whitespace().count()
}
```

Add dependencies with `cargo add crate_name` and inspect them with
`cargo tree`. Lock versions in `Cargo.lock`; commit it for applications.

## Workspaces

A workspace shares a `Cargo.lock` and target directory across multiple
packages. It is useful for a library, CLI, and integration tests living in
separate crates.

## Quality routine

```bash
cargo fmt -- --check
cargo check --all-targets
cargo clippy --all-targets --all-features -- -D warnings
cargo test --all-targets
cargo doc --no-deps --open
```

Exercises:

1. Move the parser from a binary into a library module.
2. Add a public function and document its inputs, output, and errors.
3. Add one unit test and one integration test.
4. Create a two-package workspace.

Checkpoint: explain the difference between a package, crate, module, unit
test, and integration test.

