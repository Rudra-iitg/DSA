# 09 - Threads, Channels, Async, and Performance

## Threads

```rust
use std::thread;

let handle = thread::spawn(|| {
    (1..=5).sum::<u32>()
});
let result = handle.join().expect("worker panicked");
println!("{result}");
```

The closure must own or safely borrow captured data. `move` is often required
because the new thread may outlive the current scope.

## Channels

```rust
use std::sync::mpsc;
use std::thread;

let (sender, receiver) = mpsc::channel();
thread::spawn(move || sender.send("done").expect("receiver dropped"));
println!("{}", receiver.recv().expect("worker failed"));
```

Use `Arc<Mutex<T>>` for shared mutable state, but design message passing or
immutable data first. Avoid holding locks while doing slow work.

## Async Rust

Async functions return futures; they do not run until awaited by an executor.
The standard library does not provide a general executor. Use a runtime such
as Tokio for networking and concurrent I/O:

```rust
#[tokio::main]
async fn main() {
    let value = fetch_value().await;
    println!("{value}");
}

async fn fetch_value() -> u32 {
    42
}
```

Add Tokio with `cargo add tokio --features macros,rt-multi-thread,time`.
Use `tokio::join!` for independent tasks and `tokio::spawn` for tasks that
should run concurrently. Do not block an async runtime thread with
long-running synchronous work.

## Performance workflow

1. Measure with a representative workload.
2. Use `cargo build --release`.
3. Profile before optimizing.
4. Prefer clear algorithms and data layouts.
5. Benchmark changes with Criterion rather than guessing.

Understand `Iterator` allocation, cloning, borrowing, and `String` growth.
Use `cargo tree` and `cargo audit` as part of dependency hygiene.

## Exercises

1. Spawn four workers that each calculate a partial sum and combine results.
2. Build a bounded producer/consumer queue with a channel.
3. Convert a sequential file-processing operation to Tokio tasks.
4. Measure debug versus release performance.

Checkpoint: explain the difference between a thread, a channel, a future, an
executor, and an async task.

