# 🚀 push_swap Python Tester

A comprehensive, interactive tester for the 42 School [push_swap](https://github.com/42School/push_swap) project.

## Features

- **Runs and benchmarks your `push_swap` executable for random or custom test cases.**
- **Optional integration with a `checker` program** for correctness validation (if found).
- **Supports multiple test runs** for robust statistics.
- **Statistics:** measures total, best, worst, and average moves.
- **Colorful, user-friendly terminal output and result summaries.**
- **Interactive configuration menu.**
- **42-score benchmark mapping** for 3, 5, 100, and 500-number test sets.
- **Detects errors, program timeouts, and display failures.**

---

## Requirements

- Python 3.6+  
- A compiled `./push_swap` in the same directory (run: `make` in your push_swap project).
- (Optional) A compiled `./checker` in the same directory for solution validation.

---

## Usage

```bash
python3 tester.py
```

### Command-line Options

- `-n`, `--size` &nbsp;&nbsp;&nbsp;&nbsp; : number of elements in the test cases (default: 100)
- `-t`, `--tests` &nbsp;: number of random test runs (default: 20)

**Example:**  
```bash
python3 tester.py -n 100 -t 50
python3 tester.py -n 500 -t 10
```

---

## How It Works

1. **Startup**  
   - Checks for your `push_swap` and, optionally, `checker` in the current directory.
2. **Interactive Configuration**  
   - Change test size or number of runs before launching.
3. **Test Execution**  
   - Each test:
     - Generates a unique, random integer list of the chosen size.
     - Runs your program and counts the required moves.
     - (Optionally) Feeds your program's solution into `checker` to validate correctness.
   - Tracks each test’s score, highlighting failed solutions or slow performance.
4. **Summary**  
   - At the end, displays best, worst, average moves, fails, and a 42 grading.

---

## Output Example

```
╔════════════════════════════════════════════════════════════════╗
║               🚀 PUSH_SWAP TESTER v2.0 🚀                    ║
╚════════════════════════════════════════════════════════════════╝

[Checking prerequisites...]
✓ push_swap found
✓ checker found

Current Configuration:
  • Elements (size): 100
  • Tests (steps):   20

Configuration Menu:
  [1] Change size
  [2] Change number of tests
  [3] Start testing
  [4] Exit

Test   1/20 | Moves:   588 | ✓ Excellent
Test   2/20 | Moves:   634 | ✓ Excellent
...
TEST SUMMARY

Statistics:
  Total moves:      13654
  Average moves:    682.70
  Best case:        588
  Worst case:       713
  Failed tests:     0

42 Benchmark Check:
  Target: < 700 moves for 100 elements
  Result: ✓ PASSED (Grade: 5/5)

TESTING COMPLETE
```

---

## Notes

- **No leaks checker is included.** This script only tests correctness and operations count.
- To test for memory leaks, use `valgrind` or other tools on your own.
- **Keep `push_swap` and `checker` in the script's directory or update the script if paths differ.**
- Use `make` in your push_swap directory to compile before testing!

---

## Credits

- Written for [42 School](https://1337.ma) students to rapidly evaluate push_swap performance.
- Inspired by the peer code checker workflow.

---

## License

MIT

