# 06 - Generics, Traits, Trait Objects, and Lifetimes

## Generic functions and types

```rust
fn largest<T: PartialOrd + Copy>(values: &[T]) -> Option<T> {
    values.iter().copied().max_by(|a, b| a.partial_cmp(b).unwrap())
}

struct Pair<T> {
    left: T,
    right: T,
}
```

Bounds describe capabilities, not concrete types. Prefer the smallest bound
that your function needs.

## Traits

```rust
trait Summary {
    fn summary(&self) -> String;

    fn short_summary(&self) -> String {
        self.summary().chars().take(20).collect()
    }
}

struct Article {
    title: String,
}

impl Summary for Article {
    fn summary(&self) -> String {
        self.title.clone()
    }
}
```

Static dispatch:

```rust
fn print_summary(item: &impl Summary) {
    println!("{}", item.summary());
}
```

Dynamic dispatch:

```rust
fn print_many(items: &[Box<dyn Summary>]) {
    for item in items {
        println!("{}", item.summary());
    }
}
```

Use `impl Trait` when the concrete type can remain hidden and `dyn Trait` when
different concrete types must be stored behind one interface.

## Lifetimes

```rust
fn longest<'a>(first: &'a str, second: &'a str) -> &'a str {
    if first.len() >= second.len() { first } else { second }
}
```

The lifetime does not extend anything; it states the relationship between
input and output references. Lifetime elision often lets Rust infer simple
cases. Structs that store references need annotations:

```rust
struct Label<'a> {
    text: &'a str,
}
```

## Associated types and operator traits

Traits can use `type Output` to define one related type. Standard traits worth
learning include `Debug`, `Clone`, `Copy`, `Default`, `From`, `Into`,
`Iterator`, `Display`, and `Add`.

## Exercises

1. Create a generic `Stack<T>` with `push`, `pop`, and `peek`.
2. Implement `Display` for a `User`.
3. Make two different types implement `Summary`, store them in
   `Vec<Box<dyn Summary>>`, and print them.
4. Explain why a function returning a reference to a local `String` is invalid.

Checkpoint: generics provide reusable static code, traits define behavior,
trait objects provide runtime polymorphism, and lifetimes describe reference
relationships.

