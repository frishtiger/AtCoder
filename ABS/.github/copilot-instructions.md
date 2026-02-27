# AtCoder ABS Copilot Instructions

## Project Overview
This is an **AtCoder Beginner Selection (ABS)** competitive programming practice workspace. Each `.cpp` file is an independent solution to a single AtCoder problem. No shared libraries or cross-file dependencies exist.

## Critical Workflows

### Build & Run
- **Direct compilation**: Use the workspace build task (Ctrl+Shift+B)
  - Compiles current file with: `g++ -std=gnu++17 -O2 -Wall`
  - Automatically runs the compiled `.exe` immediately
  - Requires g++ installed with C++17 support

### Input/Output Pattern
- All solutions use `std::cin` for input and `std::cout` for output
- Example (from [ABC081A.cpp](ABC081A.cpp#L98)):
  ```cpp
  std::string S;
  std::cin >> S;
  std::cout << result << '\n';
  ```

## Code Conventions

### Header Includes
- **All files include the complete C++20 standard library** (comprehensive 90+ header pattern)
- This is not optimized but ensures all functionality is available
- Headers are identical across files—do not remove individual headers when fixing issues
- Comment: `//#define _GLIBCXX_DEBUG` is available for debugging (currently disabled)

### File Naming
- Format: `{CONTEST_CODE}{PROBLEM_LETTER}.cpp` (e.g., ABC081A.cpp, ABC087B.cpp)
- Each contest has multiple problems (A, B, C, D, etc.)
- PracticeA.cpp is a generic practice file

### Main Entry Point
- All solutions have a single `int main()` function
- Direct inline logic—no helper files or shared utilities
- Use `std::cin`/`std::cout` for all I/O

## Notable Patterns

### Mathematical Utilities
- Some files include helper functions like `floordiv()` ([ABC087B.cpp](ABC087B.cpp#L94)) for floor division
- These are problem-specific utilities, not shared across files

### String/Logic Operations
- Competitive style: inline logic with conditional operators
- Example (from [ABC086A.cpp](ABC086A.cpp#L102)): Nested ternary operators checking digit parity

### Scope of Work
- Each `.cpp` file is completely independent
- When creating new solutions, follow the naming convention and include the full header block
- No refactoring across files is needed—solutions are isolated

## Common Commands
- **Compile & Run**: Press Ctrl+Shift+B (uses the default build task)
- **Edit & Test**: Modify the current `.cpp` file, then build to test immediately
