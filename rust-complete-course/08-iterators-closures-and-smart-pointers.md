# 08 - Closures, Iterators, and Smart Pointers

## Closures

```rust
let multiplier = 3;
let triple = |value: i32| value * multiplier;
assert_eq!(triple(4), 12);
```

Closures can borrow immutably, borrow mutably, or take ownership. `move`
forces captured values to be moved into the closure, which is common when
spawning a thread.

## Iterators

```rust
let total: i32 = (1..=10)
    .filter(|number| number % 2 == 0)
    .map(|number| number * number)
    .sum();
```

Iterator adapters are lazy. `map`, `filter`, `take`, `enumerate`, and `zip`
build a pipeline; consumers such as `collect`, `sum`, `count`, `find`, and
`for_each` execute it.

```rust
let names: Vec<String> = ["Ada", "Grace"]
    .into_iter()
    .map(str::to_lowercase)
    .collect();
```

Implementing `Iterator`:

```rust
struct Counter {
    current: u32,
}

impl Iterator for Counter {
    type Item = u32;

    fn next(&mut self) -> Option<Self::Item> {
        self.current += 1;
        (self.current <= 3).then_some(self.current)
    }
}
```

## Smart pointers

- `Box<T>` puts a value on the heap and gives single ownership.
- `Rc<T>` enables shared ownership in single-threaded code.
- `Arc<T>` enables shared ownership across threads.
- `RefCell<T>` checks borrowing at runtime; use only when necessary.
- `Mutex<T>` protects shared mutable data across threads.

```rust
use std::rc::Rc;

let shared = Rc::new(String::from("shared"));
let another = Rc::clone(&shared);
println!("{shared} {another}");
```

`Rc` is not thread-safe. `Arc<Mutex<T>>` is a common, but not always ideal,
multi-threaded pattern.

## Exercises

1. Rewrite a loop that filters and transforms numbers as an iterator pipeline.
2. Implement an iterator that yields Fibonacci numbers up to a limit.
3. Compare `Box`, `Rc`, and `Arc` in comments on a small example.
4. Use `fold` to calculate a sum and explain the accumulator type.

Checkpoint: identify lazy versus consuming iterator methods and choose a smart
pointer based on ownership and thread-safety requirements.

