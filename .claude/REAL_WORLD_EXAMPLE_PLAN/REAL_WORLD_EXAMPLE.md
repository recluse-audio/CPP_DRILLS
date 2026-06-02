# Real-World Example Drills — Process Plan

Goal: build out new drills (starting at 05) where each exercise is anchored
to an **authoritative, human-authored** problem from a public source
(LearnCpp, PYnative, C++ Core Guidelines, etc.) rather than an
AI-invented scenario. AI does the *mechanical scaffolding only*; all
prose content is human-sourced. Ryan approves each drill one by one.

This file is the roadmap. We execute it incrementally, refining the
process on drill 05 before applying it to 06+.

This plan lives in its own folder per the global rule: each plan gets a
`.claude/<PLAN_NAME>/` directory so delegate instructions can be kept
alongside it.

---

## DECISIONS — RESOLVED

1. **AI-touches-repo policy.** RESOLVED: special-circumstance override is
   permitted with explicit user permission (this turn). The override is
   recorded in `.claude/CLAUDE.md`, NOT in `README.org` (its Meta wording
   stays human-authored and unchanged). Scope: scaffolding/plumbing only;
   all prose human-authored. The user commits, not AI.

2. **"DOI" for web tutorials.** RESOLVED: web tutorials have no DOI. Use a
   **web.archive.org permalink** as the stable identifier
   (`#+SOURCE_ARCHIVE:`). Record a real `#+SOURCE_DOI:` only when the
   source genuinely has one (e.g. a published book/paper).

3. **Problem text.** RESOLVED: **short, attributed fair-use excerpt.** I
   paste a short excerpt under a `#+SOURCE` quote; Ryan reviews before
   commit. Keep excerpts minimal — link to the full source.

4. **Which "05".** RESOLVED: **re-base** the existing
   `05_CLASSES_AND_RAII` onto a sourced (likely RAII-themed) human
   problem. Same drill sequence, now source-anchored.

5. **Makefile + domain unit.** Assumed (confirm on 05): each drill gets a
   copied/adapted `Makefile` (mechanical plumbing); no domain
   header/impl pair until the API is defined from the problem.

---

## Candidate sources (parked — not yet vetted per-drill)

- **LearnCpp** — primary; tolerates short attributed fair-use excerpts.
- **C++ Core Guidelines**, **cppreference** — stable anchors, safe to quote.
- **GeeksforGeeks — C++ coding interview Q&A**
  https://www.geeksforgeeks.org/cpp/cpp-coding-interview-questions-and-answers/
  Useful for algorithmic drills (e.g. 03, 08). CAVEAT: GfG content is
  proprietary — **paraphrase the prompt, do not excerpt** (same concern as
  LeetCode). Poor fit for the RAII/ownership drills (05/06/09).
- **HackerRank — C++ domain**
  https://www.hackerrank.com/domains/cpp
  C++-specific track (incl. classes, STL, inheritance), so broader fit than
  pure-algorithm sites. CAVEAT: proprietary — **paraphrase, do not excerpt**.

## Conventions observed in the existing repo (match exactly)

Directory naming:
- `DRILLS/NN_TOPIC_IN_SCREAMING_SNAKE_CASE/` (e.g. `05_CLASSES_AND_RAII`)
- Two-digit zero-padded `NN`.

Per-drill tree:
```
DRILLS/NN_NAME/
  README.org          # metadata + backlink + source links + (excerpt) problem text
  Makefile            # adapted copy of the standard build/test/clean targets
  SOURCE/
    main.cpp          # ONLY the main() stub below — no other text
  TESTS/
    test_main.cpp     # left EMPTY (Ryan writes the tests)
```

`README.org` header conventions (all-caps keys, as in existing files):
- `#+TITLE: README`
- `#+AUTHOR: Ryan Devens`
- `#+FOCUS: ...`            (one-line topic, as in 04)
- plus the sourcing keys in the template below
- Org headings use `*`, `**`.

Backlink format (from existing main README → child):
```
[[file:DRILLS/NN_NAME/README.org][README_NN_NAME]]
```
Child README → main (the new backlink we add):
```
[[file:../../README.org][BACK TO MAIN README]]
```

`main.cpp` stub (Allman, matches existing 04 `main.cpp`):
```cpp
#include <iostream>

auto main(int argc, char *argv[]) -> int
{


    return 0;
}
```

Build flags: `g++ -std=c++17 -Wall -Wextra` (per existing Makefiles).

---

## Per-drill README.org template

Only the metadata keys, headings, backlink, source links, and the short
attributed excerpt are written by AI. Everything substantive is
human-sourced.

```org
#+TITLE: README
#+AUTHOR: Ryan Devens
#+FOCUS: <one-line topic>
#+SOURCE: <name of source, e.g. LearnCpp 27.x>
#+SOURCE_URL: <canonical url>
#+SOURCE_ARCHIVE: <web.archive.org permalink>     # stands in for DOI
#+SOURCE_DOI: <real DOI iff one exists, else omit>

[[file:../../README.org][BACK TO MAIN README]]

* PROBLEM
#+begin_quote
<short attributed fair-use excerpt of the source problem statement>
#+end_quote
-- <source name + url>

* OBJECTIVE
# <-- human-authored

* REQUIRED FUNCTIONS
# <-- human-authored API list
```

Main `README.org`, under `* DRILLS`, append (matching 03/04 entries):
```org
** NN_NAME
[[file:DRILLS/NN_NAME/README.org][README_NN_NAME]]
```

---

## The repeatable process (per drill)

For each new drill, in order, with an approval gate at each ★:

1. **Pick the source problem.** Propose a specific human-authored
   exercise from an authoritative source matching the drill's topic.
   ★ Ryan approves the source.
2. **Capture identifiers.** Canonical URL + archive.org permalink
   (+ real DOI only if it exists).
3. **Draft the main-README entry** (`** NN_NAME` + backlink).
   ★ Ryan approves before it's written.
4. **Create the directory tree:** `DRILLS/NN_NAME/{SOURCE,TESTS}/`.
5. **Scaffold files:** `SOURCE/main.cpp` (stub only), empty
   `TESTS/test_main.cpp`, adapted `Makefile`, `README.org` (metadata +
   backlink + source links + short attributed excerpt).
6. ★ Ryan reviews the whole drill, then commits (per repo policy).

---

## First execution: DRILL 05 (refine the process here)

Re-base `05_CLASSES_AND_RAII` onto a sourced problem.

Checklist:
- [x] Decisions #1–#4 resolved.
- [ ] Choose + approve the source RAII problem for 05.
- [ ] Record URL + archive permalink.
- [ ] Approve the `** 05_NAME` main-README entry.
- [ ] Create `DRILLS/05_NAME/{SOURCE,TESTS}/`.
- [ ] Write `SOURCE/main.cpp` (stub), empty `TESTS/test_main.cpp`,
      `Makefile`, `README.org` (metadata + backlinks + source links +
      excerpt).
- [ ] Ryan reviews → commits.

Once 05 feels right, repeat for 06+ (one drill per approval cycle).
