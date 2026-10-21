# 04 - Structs, Enums, `Option`, and Pattern Matching

## Structs

```rust
#[derive(Debug, Clone, PartialEq)]
struct User {
    name: String,
    age: u8,
    active: bool,
}

impl User {
    fn birthday(&mut self) {
        self.age += 1;
    }

    fn can_vote(&self) -> bool {
        self.age >= 18
    }
}
```

Methods take `&self`, `&mut self`, or `self`. Associated functions are called
with `User::new()` and do not receive `self`.

## Enums model alternatives

```rust
enum Shape {
    Circle { radius: f64 },
    Rectangle { width: f64, height: f64 },
}

fn area(shape: &Shape) -> f64 {
    match shape {
        Shape::Circle { radius } => std::f64::consts::PI * radius * radius,
        Shape::Rectangle { width, height } => width * height,
    }
}
```

Use `Option<T>` when a value may be absent:

```rust
fn safe_first(values: &[i32]) -> Option<i32> {
    values.first().copied()
}

let value = safe_first(&[4, 8]).unwrap_or(0);
```

Avoid `unwrap()` in code where absence is expected; use `match`, `if let`,
`unwrap_or`, or `?` as appropriate.

## Custom state machines

```rust
enum TrafficLight {
    Red,
    Yellow,
    Green,
}

fn wait_seconds(light: TrafficLight) -> u8 {
    match light {
        TrafficLight::Red => 30,
        TrafficLight::Yellow => 5,
        TrafficLight::Green => 0,
    }
}
```

## Interactive task: command parser

Build:

```rust
enum Command {
    Add(String),
    Remove(usize),
    List,
    Quit,
}
```

Write `parse_command(input: &str) -> Option<Command>`. Inputs such as
`add milk`, `remove 2`, `list`, and `quit` should work. Invalid input should
return `None`. Add tests for every valid command and at least three invalid
inputs.

## Pattern tools

```rust
let Some(first) = safe_first(&[10, 20]) else {
    return;
};
println!("{first}");
```

`if let` and `let ... else` are convenient when only one pattern is important.
`matches!` is useful in tests:

```rust
assert!(matches!(safe_first(&[1]), Some(1)));
```

Exercises:

1. Add a `Priority` enum to the parser.
2. Implement `Display` for `TrafficLight`.
3. Add a method that converts `Shape` into a human-readable description.

Checkpoint: choose a struct for “has all these fields” and an enum for “is one
of these alternatives.”

