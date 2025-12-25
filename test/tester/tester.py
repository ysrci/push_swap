#!/usr/bin/env python3

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tester <tester@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/12 10:00:00 by tester            #+#    #+#              #
#    Updated: 2025/12/12 10:00:00 by tester           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

"""
PUSH_SWAP TESTER
================
A comprehensive tester for the 42 push_swap project
Tests sorting algorithm efficiency and correctness
"""

import subprocess
import random
import argparse
import sys
import os
from typing import List, Tuple

# =============================================================================
# COLOR CODES FOR TERMINAL OUTPUT
# =============================================================================
class Colors:
    RED = '\033[91m'
    GREEN = '\033[92m'
    YELLOW = '\033[93m'
    BLUE = '\033[94m'
    MAGENTA = '\033[95m'
    CYAN = '\033[96m'
    WHITE = '\033[97m'
    BOLD = '\033[1m'
    RESET = '\033[0m'

# =============================================================================
# STATISTICS CLASS
# =============================================================================
class TestStats:
    def __init__(self):
        self.total_moves = 0
        self.best_moves = float('inf')
        self.worst_moves = 0
        self.failed_tests = 0
        self.test_results = []

    def update(self, moves: int):
        """Update statistics with a new test result"""
        self.total_moves += moves
        self.test_results.append(moves)
        if moves < self.best_moves:
            self.best_moves = moves
        if moves > self.worst_moves:
            self.worst_moves = moves

    def get_average(self) -> float:
        """Calculate average moves"""
        if not self.test_results:
            return 0
        return self.total_moves / len(self.test_results)

# =============================================================================
# HELPER FUNCTIONS
# =============================================================================

def print_header():
    """Display a beautiful header"""
    os.system('clear' if os.name == 'posix' else 'cls')
    print(f"{Colors.CYAN}{Colors.BOLD}")
    print("╔════════════════════════════════════════════════════════════════╗")
    print("║                                                                ║")
    print("║               🚀 PUSH_SWAP TESTER v2.0 🚀                     ║")
    print("║                                                                ║")
    print("║                    42 School Project                          ║")
    print("║                                                                ║")
    print("╚════════════════════════════════════════════════════════════════╝")
    print(f"{Colors.RESET}\n")

def check_prerequisites() -> bool:
    """Check if required executables exist"""
    print(f"{Colors.BLUE}{Colors.BOLD}[Checking prerequisites...]{Colors.RESET}")

    # Check push_swap
    if not os.path.isfile("./push_swap"):
        print(f"{Colors.RED}{Colors.BOLD}✗ Error: ./push_swap not found!{Colors.RESET}")
        print(f"{Colors.YELLOW}  Please compile push_swap first with: make{Colors.RESET}")
        return False

    if not os.access("./push_swap", os.X_OK):
        print(f"{Colors.RED}{Colors.BOLD}✗ Error: ./push_swap is not executable!{Colors.RESET}")
        return False

    print(f"{Colors.GREEN}{Colors.BOLD}✓ push_swap found{Colors.RESET}")

    # Check checker (optional)
    checker_available = False
    if os.path.isfile("./checker"):
        if os.access("./checker", os.X_OK):
            print(f"{Colors.GREEN}{Colors.BOLD}✓ checker found{Colors.RESET}")
            checker_available = True
        else:
            print(f"{Colors.RED}{Colors.BOLD}✗ Error: ./checker is not executable!{Colors.RESET}")
            return False
    else:
        print(f"{Colors.YELLOW}⚠ Warning: ./checker not found!{Colors.RESET}")
        print(f"{Colors.YELLOW}  Tester will only count moves, not validate correctness.{Colors.RESET}")

    print()
    return True, checker_available

def generate_random_numbers(size: int) -> List[int]:
    """Generate a list of unique random integers"""
    range_size = size * 10  # Ensure enough range for uniqueness
    numbers = random.sample(range(-range_size, range_size), size)
    return numbers

def run_push_swap(numbers: List[int]) -> Tuple[List[str], int]:
    """
    Run push_swap with given numbers
    Returns: (list of operations, number of moves)
    """
    try:
        # Convert numbers to string arguments
        args = [str(n) for n in numbers]

        # Run push_swap
        result = subprocess.run(
            ["./push_swap"] + args,
            capture_output=True,
            text=True,
            timeout=10
        )

        # Parse output
        operations = [line.strip() for line in result.stdout.strip().split('\n') if line.strip()]
        moves = len(operations)

        return operations, moves

    except subprocess.TimeoutExpired:
        print(f"{Colors.RED}✗ Timeout: push_swap took too long!{Colors.RESET}")
        return [], -1
    except Exception as e:
        print(f"{Colors.RED}✗ Error running push_swap: {e}{Colors.RESET}")
        return [], -1

def validate_with_checker(numbers: List[int], operations: List[str]) -> bool:
    """
    Validate the sorting using checker
    Returns: True if OK, False otherwise
    """
    try:
        # Convert numbers to string arguments
        args = [str(n) for n in numbers]

        # Run checker with operations as input
        operations_input = '\n'.join(operations) + '\n'
        result = subprocess.run(
            ["./checker"] + args,
            input=operations_input,
            capture_output=True,
            text=True,
            timeout=10
        )

        return result.stdout.strip() == "OK"

    except subprocess.TimeoutExpired:
        print(f"{Colors.RED}✗ Checker timeout!{Colors.RESET}")
        return False
    except Exception as e:
        print(f"{Colors.RED}✗ Error running checker: {e}{Colors.RESET}")
        return False

def get_performance_color(moves: int, size: int) -> str:
    """Get color based on performance for given size"""
    if size == 100:
        if moves < 700:
            return Colors.GREEN
        elif moves < 900:
            return Colors.YELLOW
        elif moves < 1500:
            return Colors.YELLOW
        else:
            return Colors.RED
    elif size == 500:
        if moves < 5500:
            return Colors.GREEN
        elif moves < 7000:
            return Colors.YELLOW
        elif moves < 8500:
            return Colors.YELLOW
        else:
            return Colors.RED
    else:
        return Colors.GREEN

def get_performance_label(moves: int, size: int) -> str:
    """Get performance label based on moves"""
    if size == 100:
        if moves < 700:
            return "✓ Excellent"
        elif moves < 900:
            return "○ Good"
        elif moves < 1100:
            return "○ Average"
        elif moves < 1300:
            return "△ Below average"
        else:
            return "✗ Poor"
    elif size == 500:
        if moves < 5500:
            return "✓ Excellent"
        elif moves < 7000:
            return "○ Good"
        elif moves < 8500:
            return "○ Average"
        else:
            return "✗ Poor"
    else:
        return "✓ Complete"

def calculate_grade(average: float, size: int) -> int:
    """Calculate grade based on 42 evaluation criteria"""
    if size == 3:
        if average <= 3:
            return 5
        elif average <= 5:
            return 3
        return 0
    elif size == 5:
        if average <= 12:
            return 5
        return 0
    elif size == 100:
        if average < 700:
            return 5
        elif average < 900:
            return 4
        elif average < 1100:
            return 3
        elif average < 1300:
            return 2
        elif average < 1500:
            return 1
        return 0
    elif size == 500:
        if average < 5500:
            return 5
        elif average < 7000:
            return 4
        elif average < 8500:
            return 3
        elif average < 10000:
            return 2
        elif average < 11500:
            return 1
        return 0
    return 0

def print_test_result(test_num: int, total_tests: int, moves: int, size: int):
    """Print individual test result"""
    color = get_performance_color(moves, size)
    label = get_performance_label(moves, size)

    print(f"{Colors.CYAN}Test {test_num:3d}/{total_tests}{Colors.RESET} | "
          f"Moves: {Colors.MAGENTA}{moves:5d}{Colors.RESET} | "
          f"{color}{label}{Colors.RESET}")

def print_summary(stats: TestStats, size: int, tests: int):
    """Display final statistics and benchmark results"""
    average = stats.get_average()
    grade = calculate_grade(average, size)

    print()
    print(f"{Colors.CYAN}{Colors.BOLD}╔════════════════════════════════════════════════════════════════╗{Colors.RESET}")
    print(f"{Colors.CYAN}{Colors.BOLD}║                        TEST SUMMARY                            ║{Colors.RESET}")
    print(f"{Colors.CYAN}{Colors.BOLD}╚════════════════════════════════════════════════════════════════╝{Colors.RESET}")
    print()

    print(f"{Colors.BOLD}Configuration:{Colors.RESET}")
    print(f"  Elements to sort: {Colors.MAGENTA}{size}{Colors.RESET}")
    print(f"  Number of tests:  {Colors.MAGENTA}{tests}{Colors.RESET}")
    print()

    print(f"{Colors.BOLD}Statistics:{Colors.RESET}")
    print(f"  Total moves:      {Colors.CYAN}{stats.total_moves}{Colors.RESET}")
    print(f"  Average moves:    {Colors.YELLOW}{average:.2f}{Colors.RESET}")
    print(f"  Best case:        {Colors.GREEN}{stats.best_moves}{Colors.RESET}")
    print(f"  Worst case:       {Colors.RED}{stats.worst_moves}{Colors.RESET}")
    print(f"  Failed tests:     {Colors.RED}{stats.failed_tests}{Colors.RESET}")
    print()

    # 42 Benchmark Check
    print(f"{Colors.BOLD}42 Benchmark Check:{Colors.RESET}")

    if size == 100:
        print(f"  Target: < 700 moves for 100 elements")
        if average < 700:
            print(f"  Result: {Colors.GREEN}{Colors.BOLD}✓ PASSED{Colors.RESET} "
                  f"(Grade: {Colors.GREEN}{grade}/5{Colors.RESET})")
        elif average < 900:
            print(f"  Result: {Colors.YELLOW}{Colors.BOLD}○ GOOD{Colors.RESET} "
                  f"(Grade: {Colors.YELLOW}{grade}/5{Colors.RESET})")
        elif average < 1100:
            print(f"  Result: {Colors.YELLOW}{Colors.BOLD}○ AVERAGE{Colors.RESET} "
                  f"(Grade: {Colors.YELLOW}{grade}/5{Colors.RESET})")
        elif average < 1500:
            print(f"  Result: {Colors.RED}{Colors.BOLD}△ BELOW AVERAGE{Colors.RESET} "
                  f"(Grade: {Colors.RED}{grade}/5{Colors.RESET})")
        else:
            print(f"  Result: {Colors.RED}{Colors.BOLD}✗ FAILED{Colors.RESET} "
                  f"(Grade: {Colors.RED}{grade}/5{Colors.RESET})")

    elif size == 500:
        print(f"  Target: < 5500 moves for 500 elements")
        if average < 5500:
            print(f"  Result: {Colors.GREEN}{Colors.BOLD}✓ PASSED{Colors.RESET} "
                  f"(Grade: {Colors.GREEN}{grade}/5{Colors.RESET})")
        elif average < 7000:
            print(f"  Result: {Colors.YELLOW}{Colors.BOLD}○ GOOD{Colors.RESET} "
                  f"(Grade: {Colors.YELLOW}{grade}/5{Colors.RESET})")
        elif average < 8500:
            print(f"  Result: {Colors.YELLOW}{Colors.BOLD}○ AVERAGE{Colors.RESET} "
                  f"(Grade: {Colors.YELLOW}{grade}/5{Colors.RESET})")
        else:
            print(f"  Result: {Colors.RED}{Colors.BOLD}✗ FAILED{Colors.RESET} "
                  f"(Grade: {Colors.RED}{grade}/5{Colors.RESET})")

    elif size == 3:
        print(f"  Target: ≤ 3 moves for 3 elements")
        if average <= 3:
            print(f"  Result: {Colors.GREEN}{Colors.BOLD}✓ PASSED{Colors.RESET} "
                  f"(Grade: {Colors.GREEN}5/5{Colors.RESET})")
        else:
            print(f"  Result: {Colors.RED}{Colors.BOLD}✗ FAILED{Colors.RESET} "
                  f"(Grade: {Colors.RED}{grade}/5{Colors.RESET})")

    elif size == 5:
        print(f"  Target: ≤ 12 moves for 5 elements")
        if average <= 12:
            print(f"  Result: {Colors.GREEN}{Colors.BOLD}✓ PASSED{Colors.RESET} "
                  f"(Grade: {Colors.GREEN}5/5{Colors.RESET})")
        else:
            print(f"  Result: {Colors.RED}{Colors.BOLD}✗ FAILED{Colors.RESET} "
                  f"(Grade: {Colors.RED}0/5{Colors.RESET})")

    else:
        print(f"  {Colors.YELLOW}No standard benchmark for size {size}{Colors.RESET}")

    print()
    print(f"{Colors.CYAN}{Colors.BOLD}╔════════════════════════════════════════════════════════════════╗{Colors.RESET}")
    print(f"{Colors.CYAN}{Colors.BOLD}║                    TESTING COMPLETE                            ║{Colors.RESET}")
    print(f"{Colors.CYAN}{Colors.BOLD}╚════════════════════════════════════════════════════════════════╝{Colors.RESET}")
    print()

# =============================================================================
# MAIN TESTING FUNCTION
# =============================================================================

def run_tests(size: int, num_tests: int, checker_available: bool):
    """Run all tests and collect statistics"""
    stats = TestStats()

    print(f"{Colors.BLUE}{Colors.BOLD}[Starting tests...]{Colors.RESET}")
    print(f"{Colors.YELLOW}Configuration: {size} elements, {num_tests} tests{Colors.RESET}\n")

    for i in range(1, num_tests + 1):
        # Generate random numbers
        numbers = generate_random_numbers(size)

        # Run push_swap
        operations, moves = run_push_swap(numbers)

        if moves == -1:
            print(f"{Colors.RED}✗ Test {i} FAILED: Error running push_swap{Colors.RESET}")
            stats.failed_tests += 1
            continue

        # Validate with checker if available
        if checker_available:
            is_valid = validate_with_checker(numbers, operations)
            if not is_valid:
                print(f"{Colors.RED}{Colors.BOLD}✗ Test {i} FAILED: Checker returned KO{Colors.RESET}")
                print(f"{Colors.YELLOW}  Numbers: {' '.join(map(str, numbers[:10]))}...{Colors.RESET}")
                print(f"{Colors.YELLOW}  Moves: {moves}{Colors.RESET}")
                stats.failed_tests += 1

                # Ask user if they want to continue
                response = input(f"\n{Colors.YELLOW}Continue testing? (y/n): {Colors.RESET}")
                if response.lower() != 'y':
                    print(f"{Colors.RED}Testing aborted by user.{Colors.RESET}")
                    sys.exit(1)
                continue

        # Update statistics
        stats.update(moves)

        # Print test result
        print_test_result(i, num_tests, moves, size)

    return stats

# =============================================================================
# MAIN ENTRY POINT
# =============================================================================

def main():
    """Main function"""

    # Parse command line arguments
    parser = argparse.ArgumentParser(
        description='Push_swap tester for 42 School project',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  %(prog)s -n 100 -t 50    # Test with 100 numbers, 50 times
  %(prog)s -n 500 -t 10    # Test with 500 numbers, 10 times
        """
    )

    parser.add_argument('-n', '--size', type=int, default=100,
                        help='Number of elements to sort (default: 100)')
    parser.add_argument('-t', '--tests', type=int, default=20,
                        help='Number of tests to run (default: 20)')

    args = parser.parse_args()

    # Display header
    print_header()

    # Check prerequisites
    result = check_prerequisites()
    if isinstance(result, tuple):
        success, checker_available = result
        if not success:
            sys.exit(1)
    else:
        sys.exit(1)

    # ================================
    #  INTERACTIVE CONFIG TOOL
    # ================================
    while True:
        print(f"{Colors.BOLD}{Colors.CYAN}Current Configuration:{Colors.RESET}")
        print(f"  • Elements (size): {Colors.YELLOW}{args.size}{Colors.RESET}")
        print(f"  • Tests (steps):   {Colors.YELLOW}{args.tests}{Colors.RESET}\n")

        print(f"{Colors.BOLD}{Colors.GREEN}Configuration Menu:{Colors.RESET}")
        print("  [1] Change size")
        print("  [2] Change number of tests")
        print("  [3] Start testing")
        print("  [4] Exit\n")

        choice = input(f"{Colors.CYAN}Select option: {Colors.RESET}").strip()

        if choice == "1":
            new_size = input("Enter new size (number of elements): ").strip()
            if new_size.isdigit() and int(new_size) > 0:
                args.size = int(new_size)
            else:
                print(f"{Colors.RED}Invalid size!{Colors.RESET}")

        elif choice == "2":
            new_tests = input("Enter number of tests: ").strip()
            if new_tests.isdigit() and int(new_tests) > 0:
                args.tests = int(new_tests)
            else:
                print(f"{Colors.RED}Invalid number of tests!{Colors.RESET}")

        elif choice == "3":
            print(f"{Colors.GREEN}Starting tests...{Colors.RESET}\n")
            break

        elif choice == "4":
            print(f"{Colors.RED}Exiting tester.{Colors.RESET}")
            sys.exit(0)

        else:
            print(f"{Colors.RED}Invalid option! Please choose 1–4.{Colors.RESET}")

    # ================================
    #  RUN TESTS
    # ================================
    stats = run_tests(args.size, args.tests, checker_available)

    # ================================
    #  SUMMARY
    # ================================
    print_summary(stats, args.size, args.tests)

    # Exit with status depending on failures
    sys.exit(1 if stats.failed_tests > 0 else 0)

if __name__ == "__main__":
    main()
