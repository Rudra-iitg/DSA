# 03 - Ownership, Borrowing, References, and Slices

Ownership is Rust's core memory-safety system:

1. Every value has one owner.
2. There can be only one owner at a time.
3. When the owner leaves scope, the value is dropped.

## Move versus copy

```rust
let first = String::from("hello");
let second = first; // moves the String
println!("{second}"); // `first` cannot be used here

let a = 10;
let b = a; // integers implement Copy
println!("{a} {b}");
```

Heap-owning types such as `String` move. Simple fixed-size types such as
integers and booleans copy.

## Borrowing

Pass a reference when a function should read without taking ownership:

```rust
fn word_count(text: &str) -> usize {
    text.split_whitespace().count()
}

fn add_exclamation(text: &mut String) {
    text.push('!');
}

fn main() {
    let mut message = String::from("hello rust");
    println!("{}", word_count(&message));
    add_exclamation(&mut message);
    println!("{message}");
}
```

Rust allows either many immutable references or one mutable reference, but
not both at the same time. A reference must never outlive its value.

## Slices

`&str` is a string slice. `&[T]` is a slice of an array or vector:

```rust
fn first_word(text: &str) -> &str {
    text.split_whitespace().next().unwrap_or("")
}

fn largest(numbers: &[i32]) -> Option<i32> {
    numbers.iter().copied().max()
}
```

The slice does not own the data. This makes APIs flexible: both arrays and
vectors can be passed as `&[i32]`.

## Predict the compiler

Why does this fail?

```rust
let mut name = String::from("Ada");
let view = &name;
name.push_str(" Lovelace");
println!("{view}");
```

The immutable borrow is still used after the attempted mutation. Fix it by
printing `view` before the mutation, or by ending the borrow before mutating.

This also fails:

```rust
let reference_to_nothing = {
    let value = String::from("temporary");
    &value
};
```

The returned reference would outlive `value`.

## Exercises

1. Implement `reverse_words(text: &str) -> String`.
2. Write `fn longest<'a>(a: &'a str, b: &'a str) -> &'a str` and explain why
   the lifetime annotation is needed.
3. Write a function that changes a `Vec<i32>` through `&mut Vec<i32>`.
4. Use `cargo check` and read the full borrow-checker error instead of
   immediately changing code.

Checkpoint: explain who owns a `String`, what `&String` versus `&str` means,
and why simultaneous mutable and immutable access is rejected.

