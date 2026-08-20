# Object-Oriented Programming Labs (C++)

A progression of C++ labs covering core OOP concepts, from basic classes to templates and multithreading. Built for a university OOP course.

## What's inside

| Folder | Topic |
|---|---|
| `lab1/` | **Keyboard Trainer** — a typing-practice console app: generates a random string, times how accurately/quickly the user retypes it |
| `lab2/` `lab3/` | Class design with **inheritance & polymorphism** — an abstract `Function` base class with `Exponenta` and `NaturalLogarifm` subclasses, each computing their result via a virtual `calc()` method (Taylor series) |
| `lab4/` | A 3D **`Vector` class** (x, y, z) with encapsulated fields and accessor methods |
| `lab6/` | **C++ templates** — a generic comparison structure (`compare_struct<T>`) with a full template specialization for `const char*` |
| `lab7/` | Smart pointers / RAII-style object management with randomized test data |
| `lab8/` | **Multithreaded numerical integration** (rectangle method) — computes a definite integral using a configurable number of threads and benchmarks speedup & parallel efficiency as thread count increases |

## Tech stack

C++ (Windows/MSVC, `<thread>`, `<chrono>`), console I/O.

## Building & running

Each lab is a standalone project — compile the `main.cpp` in the lab folder together with any accompanying `.cpp`/`.h` files, e.g.:

```bash
g++ -std=c++17 lab8/main.cpp -pthread -o lab8
./lab8
```

## Why it matters

This series walks through the core OOP toolbox — encapsulation, inheritance, polymorphism, templates/generics — and finishes with a practical multithreading/performance-analysis exercise (measuring real speedup and efficiency of parallel work), which is a step above typical "hello world" OOP coursework.
