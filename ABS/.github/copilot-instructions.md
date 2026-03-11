# AtCoder ABS — Copilot Instructions (style-locked)

Purpose: produce C++ solutions that match the author's exact, repeatable style. Follow these rules when adding or editing solutions.

1) Project shape
- Single-file solutions only: every problem is solved in one `.cpp` (e.g., `ABC081A.cpp`, `ABC087B.cpp`). Do not introduce shared utility files.
- File naming: `{CONTEST_CODE}{PROBLEM_LETTER}.cpp`. Use `PracticeA.cpp` for throwaway tests.

2) Build & run (workspace task)
- Use the provided build task (Ctrl+Shift+B). Command used by the task:
  ```powershell
  g++ -std=gnu++17 -O2 -Wall "${file}" -o "${fileBasenameNoExtension}.exe"; .\${fileBasenameNoExtension}.exe
  ```

3) Top-of-file header block (must preserve)
- All files intentionally start with an explicit, exhaustive set of standard headers (see `ABC081A.cpp`). When creating/editing a solution, copy that header block rather than pruning headers.
- Keep the commented debug macro as present: `//#define _GLIBCXX_DEBUG`.

4) Coding idioms to mimic exactly
- I/O: `std::cin` / `std::cout` only; terminate outputs with `\n`.
- Naming: short variable names are normal for contest code (`N`, `A`, `B`, `C`, `s`, etc.). Prefer brevity that matches surrounding code.
- Compact expressions: nested ternary operators and inline logic are acceptable and common (see `ABC081A.cpp`).
- Helpers: add small problem-specific functions inside the same file if needed (example: `floordiv()` in `ABC087B.cpp`). Keep helpers local to the `.cpp`.

5) Performance & flags
- Target: `-std=gnu++17 -O2 -Wall`. Use `long long` for 64-bit integers when appropriate.

6) Small conventions
- `return 0;` in `main()` is optional — follow the pattern in the file being edited.
- Preserve top-header ordering and formatting for consistent diffs.

7) Examples to copy
- Header block + commented debug macro: see `ABC081A.cpp`.
- Nested ternary output pattern: see `ABC081A.cpp`.
- Problem-specific helper function (`floordiv`): see `ABC087B.cpp`.

8) When editing existing files
- Keep edits surgical. Avoid removing the header block or consolidating headers unless explicitly requested.

If you'd like stricter templates (smaller header set, enforced `ios::sync_with_stdio(false)`, or a minimal file stub), tell me which preference to apply and I will update this guide and add a template file.
