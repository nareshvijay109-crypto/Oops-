# Assignment 2 – CO2

**Student:** Naresh Vijay R  
**Register Number:** 1972260060  
**Course:** C++ Programming / Data Structures

## Tasks
- Task01: Call by value, reference and pointer; returned value and output prediction.
- Task02: Return by reference, const reference, copy and dangling-reference warning.
- Task03: Function overloading and default arguments.
- Task04: SavingsAccount with a 10-entry circular transaction history.
- Task05: Static members and arrays of BusTicket objects.
- Task06: Friend and inline functions for time calculations.
- Task07: Compare shift-array history with a circular buffer.

## Compile
Use C++17:
```bash
g++ -std=c++17 -Wall -Wextra -pedantic Task01/task01.cpp -o task01
./task01
```

Task02 deliberately contains a function returning a reference to a local variable to demonstrate the compiler warning. It is not called because using that dangling reference is undefined behaviour. Benchmark timings vary by machine and compiler.

Repository: https://github.com/nareshvijay109-crypto/Oops-
