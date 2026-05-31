# C++ Drills Plan — Interview Prep (Drills 03–10)

Audience: you (Ryan). Editor: Emacs. Goal: a coding-skills demo for a C++
interview. Per repo policy in README.org, **no code is written by AI** —
this file is just a roadmap you implement by hand. All implementations
must be yours.

## Pattern to keep (matches 01 + 02)

Each drill is a self-contained folder `NN_NAME/` with:

```
NN_NAME/
  Makefile           # build + test + clean targets
  SOURCE/
    main.cpp         # tiny driver / demo
    Foo.h, Foo.cpp   # the actual unit under test
  TESTS/
    test_main.cpp    # plain <cassert> tests, prints "all tests passed"
  BUILD/             # populated by `make`
```

Conventions:
- `g++ -std=c++17 -Wall -Wextra` (consider bumping to `-std=c++20` from drill 06+).
- Build artifact: `BUILD/<drill_name>_build`.
- Test artifact: `TESTS/<drill_name>_tests_build`, run by `make test`.
- Header declares the API + a one-line `//` comment per function.
- Tests cover: trivial case, base case, edge case (0, empty, 1, max), one "interesting" case.

## Interview-relevant skill coverage

The eight remaining drills are chosen so that by drill 10 you will have
demonstrated, in code you wrote unaided: pointers/references, RAII,
the rule of 0/3/5, templates, STL containers + algorithms, iterators,
move semantics, smart pointers, polymorphism, exceptions, and a small
end-to-end program tying it all together. These are the things
interviewers actually probe in a live C++ session.

---

## 03_STRINGS_AND_VECTORS
**Focus:** `std::string`, `std::vector<T>`, range-for, references vs copies.

**Scenario:** You're writing the parser for a CSV-ish log file
("`2026-05-30, login, ryan`"). The tools you build here — split,
trim, join — are the small primitives every line-oriented tool
(grep, awk, your future log analyzer) leans on.

API ideas (`Strings.h` / `Vectors.h`):
- `std::string reverse(const std::string& s);`
- `std::string trim(const std::string& s);` // strip leading/trailing whitespace
- `std::vector<std::string> split(const std::string& s, char delim);`
- `std::string join(const std::vector<std::string>& parts, const std::string& sep);`
- `int sum(const std::vector<int>& v);`
- `void in_place_double(std::vector<int>& v);` // demonstrates pass-by-ref

Interview talking points: when to take `const T&` vs `T` vs `T&`, why
`std::string` already manages its own memory, iterator invalidation on
`push_back`.

## 04_POINTERS_REFS_AND_ARRAYS
**Focus:** raw pointers, references, C arrays vs `std::array`, pointer
arithmetic — the "I understand memory" drill.

**Scenario:** You're maintaining a legacy C audio-buffer routine that
takes `(int* samples, size_t n)` and you have to interop with it from
modern C++. No `std::vector` allowed at the boundary. You need to
search, reverse, and measure these raw buffers safely.

API ideas (`Mem.h`):
- `void swap_by_ref(int& a, int& b);`
- `void swap_by_ptr(int* a, int* b);`
- `int* find(int* begin, int* end, int target);` // returns nullptr if missing
- `std::size_t c_strlen(const char* s);`
- `void reverse_in_place(int* arr, std::size_t n);`

Tests should include `nullptr` handling and the empty-range case.
Talking points: pointer == address, reference == alias, decay of arrays
to pointers, why `end` is one-past-the-last.

## 05_CLASSES_AND_RAII
**Focus:** ctor/dtor, member init lists, `const` methods, `this`, RAII.

**Scenario:** You're instrumenting a slow function in a server and need
(a) to time it without leaking timer state across calls and (b) to
read its config file without ever leaving a file handle open — even if
the function throws halfway through. Stopwatch + FileGuard are the
two tools you reach for.

Build a `Stopwatch` (start/stop/elapsed) AND a `FileGuard` that opens a
file in the ctor and closes it in the dtor — the canonical RAII demo.

API ideas:
- `class Stopwatch { void start(); void stop(); double elapsed_ms() const; };`
- `class FileGuard { explicit FileGuard(const std::string& path); ~FileGuard(); bool good() const; std::string read_all(); };`

Talking points: "resource acquisition is initialization," why dtors must
not throw, why `good() const` is `const`.

## 06_RULE_OF_FIVE_AND_MOVE
**Focus:** ownership, deep copy vs move, `=default`, `=delete`.

**Scenario:** You're writing an image-processing pipeline where each
stage hands a pixel `Buffer` to the next. Copying every frame would
tank performance, so frames must *move* between stages — but unit
tests still need to copy a frame to snapshot it for comparison. You
need both, correctly.

Build a `Buffer` class that owns a heap-allocated `int*` of size `n`
(no `std::vector` — that's the point). Implement all five:
- destructor
- copy constructor + copy assignment (deep copy)
- move constructor + move assignment (steal + null out source)

Add `at(i)` with bounds check (throws `std::out_of_range`), `size()`,
and a static counter of live instances so tests can assert no leaks.

Talking points: rule of 0/3/5, why move leaves the source "valid but
unspecified," `noexcept` on move ops and why it matters for `std::vector`
reallocation.

## 07_TEMPLATES_AND_GENERICS
**Focus:** function templates, class templates, basic type constraints.

**Scenario:** Your team keeps re-implementing the same "undo stack" in
three places — one for `int` edit positions, one for `std::string`
commands, one for a custom `Edit` struct. You're consolidating them
into one generic `Stack<T>` plus the small helper templates the team
keeps copy-pasting.

API ideas (`Generic.h`):
- `template <typename T> const T& max_of(const T& a, const T& b);`
- `template <typename It, typename T> It linear_find(It begin, It end, const T& v);`
- `template <typename T> class Stack { void push(T); T pop(); bool empty() const; std::size_t size() const; private: std::vector<T> data_; };`

Tests should instantiate with `int`, `std::string`, and a custom struct.
Talking points: template instantiation happens at use, why templates
live in headers, `typename` vs `class`.

## 08_STL_ALGORITHMS_AND_ITERATORS
**Focus:** `<algorithm>` + iterators + lambdas. Almost no hand-written loops.

**Scenario:** Product asks for a quick "top-10 search terms today"
report from a day's worth of query logs. You build the analytics
primitives — word count, top-k, dedup — the way an experienced C++
dev would: by composing `<algorithm>` calls, not writing index loops.

Implement (using `<algorithm>` underneath, not raw loops):
- `std::vector<int> unique_sorted(std::vector<int> v);` // sort + unique + erase
- `int count_if_even(const std::vector<int>& v);`
- `std::map<std::string,int> word_count(const std::string& text);`
- `std::vector<int> top_k(const std::vector<int>& v, std::size_t k);` // partial_sort

Talking points: iterator categories, why `std::map` is ordered, when to
reach for `std::unordered_map`, lambdas + captures.

## 09_SMART_POINTERS_AND_POLYMORPHISM
**Focus:** `std::unique_ptr`, `std::shared_ptr`, virtual dtors, dynamic dispatch.

**Scenario:** You're building the rendering side of a tiny vector-
drawing app. The canvas holds a heterogeneous list of shapes that all
need to answer `area()` (for hit-testing) and clean themselves up
without leaks when the canvas is cleared. Classic polymorphism + owned
heap objects.

Build a tiny shape hierarchy:
- `class Shape { public: virtual double area() const = 0; virtual ~Shape() = default; };`
- `class Circle : public Shape { ... };`
- `class Rectangle : public Shape { ... };`
- `double total_area(const std::vector<std::unique_ptr<Shape>>& shapes);`
- A factory: `std::unique_ptr<Shape> make_shape(const std::string& kind, double a, double b = 0);`

Talking points: why the base dtor is virtual, slicing, `unique_ptr` vs
`shared_ptr` vs raw pointer (non-owning view), `override` keyword.

## 10_MINI_PROJECT_TODO_CLI
**Focus:** put it all together — a small but real program you can demo live.

**Scenario:** Live in the interview: "build me a small command-line
TODO app, persisted to disk, with tests." This is the drill that
proves you can ship — file I/O, a domain class, a separable storage
layer, a CLI loop, and tests, all in one sitting.

Build a command-line TODO list:
- Add / list / complete / delete tasks
- Persist to a text file (RAII `FileGuard`-style)
- `Task` class with id, title, done flag, created-at timestamp
- Storage layer separate from CLI layer (so it's unit-testable)
- Tests cover the storage layer round-trip (add → save → load → assert)

Demo script for the interview: open in Emacs, walk the headers first
(API before implementation), then run `make test`, then run the
binary and exercise add/list/complete in the terminal.

---

## Suggested cadence

Do them in order — each one assumes the previous. 1–2 drills per
sitting is realistic if you're also reading around the topic. When you
finish each drill, append a `** NN_NAME` block to `README.org` in the
same shape as the existing 01/02 entries (you write that, not AI).

## What I deliberately left out

- Concurrency (`std::thread`, mutexes, atomics) — high-value but a whole
  separate track; add as drill 11+ once the fundamentals are solid.
- Networking, build systems beyond Make, third-party libs — out of scope
  for "fundamentals worth committing to memory."
- GoogleTest / Catch2 — `<cassert>` keeps the test layer trivial and
  matches your current pattern.
