# 10 - Capstone: A Tested Command-Line Task Manager

This lesson combines the course into one project. Build it incrementally; do
not copy everything at once.

## Requirements

Create a Cargo package:

```bash
cargo new task-manager
cd task-manager
cargo add clap --features derive
cargo add serde --features derive
cargo add serde_json
cargo add anyhow
```

The application should:

- Add a task with a title.
- List tasks.
- Mark a task complete.
- Remove a task.
- Save and load JSON.
- Return useful errors instead of panicking.
- Include unit and integration tests.

## Suggested design

```rust
#[derive(Debug, Clone, serde::Serialize, serde::Deserialize, PartialEq)]
pub struct Task {
    pub id: u64,
    pub title: String,
    pub completed: bool,
}

#[derive(clap::Parser, Debug)]
enum Command {
    Add { title: String },
    List,
    Complete { id: u64 },
    Remove { id: u64 },
}
```

Keep persistence in `storage.rs`, task operations in `tasks.rs`, and CLI
translation in `main.rs`. Make the library functions easy to test without
launching a process.

## Development loop

For every feature:

```bash
cargo fmt
cargo check
cargo test
cargo clippy -- -D warnings
cargo run -- add "Learn ownership"
cargo run -- list
```

First implement an in-memory `Vec<Task>`. Then add JSON persistence. Finally
add command parsing and friendly output. Test empty lists, duplicate IDs,
missing IDs, malformed JSON, and file I/O errors.

## Graduation checklist

You are ready for the next level when you can:

- Read compiler errors about moves, borrows, lifetimes, and trait bounds.
- Design APIs using slices, `Option`, and `Result`.
- Split code into modules with a clear public interface.
- Write unit and integration tests.
- Use iterators without hiding complicated logic.
- Choose between threads and async tasks.
- Read crate documentation and evaluate dependencies.
- Explain why unsafe code is unnecessary for your current feature.

## What to study next

- The official Rust Book: <https://doc.rust-lang.org/book/>
- Rust by Example: <https://doc.rust-lang.org/rust-by-example/>
- Standard library API: <https://doc.rust-lang.org/std/>
- Rustonomicon for unsafe Rust: <https://doc.rust-lang.org/nomicon/>
- Tokio tutorial: <https://tokio.rs/tokio/tutorial>

## A practical 30-day plan

Days 1-3: lessons 1-2 and small console programs.  
Days 4-7: ownership, borrowing, structs, and enums.  
Days 8-12: collections, `Result`, and file I/O.  
Days 13-16: generics, traits, lifetimes, and modules.  
Days 17-20: tests, iterators, closures, and smart pointers.  
Days 21-24: threads, channels, and async basics.  
Days 25-30: complete, test, document, and refactor the capstone.

Do not merely read: type every example, predict failures, run the compiler,
and write your own variation after each checkpoint.
