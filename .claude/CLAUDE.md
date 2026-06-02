# Project instructions — CPP_DRILLS

## Repo "no AI modification" policy + override

The root `README.org` Meta states this repo is not to be modified in any
way by AI tools or automated code generation, and `DRILLS_PLAN.md` repeats
that no code is written by AI. Honor that by default.

**Override:** AI may modify the repo *only* in a special circumstance with
explicit user guidance and permission to override, given in the current
turn. When overriding, stay within the scope the user grants (e.g.
"scaffolding/plumbing only; all prose human-authored"). Do **not** edit
the README.org Meta wording to reflect this — the override lives here, in
the Claude instructions, not in the repo's human-authored docs.

## Real-world example drills

See `.claude/REAL_WORLD_EXAMPLE_PLAN/REAL_WORLD_EXAMPLE.md` for the process
of building source-anchored drills (05+). Standing rules from that plan:
- AI writes only metadata, backlinks, source links, and `main()` stubs.
- Problem text enters as a short, attributed, fair-use excerpt the user
  reviews before commit (never AI-generated prose).
- Web sources have no DOI; use a web.archive.org permalink as the stable
  identifier, and a real DOI only when one genuinely exists.
- The user creates commits, not AI.
