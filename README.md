*This project has been created as part of the 42 curriculum by mcarvalh.*

---

## Description

This repository contains the **C++ Piscine** modules from the 42 school curriculum — a series of progressively challenging exercises designed to introduce object-oriented programming concepts in C++98.

Each module (CPP_00 through CPP_09) focuses on a specific set of concepts:

| Module | Topics |
|--------|--------|
| CPP_00 | Namespaces, classes, member functions, stdio streams, initialization lists |
| CPP_01 | Memory allocation, pointers to members, references, switch statements |
| CPP_02 | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form |
| CPP_03 | Inheritance |
| CPP_04 | Subtype polymorphism, abstract classes, interfaces |
| CPP_05 | Repetition and Exceptions |
| CPP_06 | C++ casts |
| CPP_07 | C++ templates |
| CPP_08 | Templated containers, iterators, algorithms |
| CPP_09 | STL containers in practice (stack, map, deque) |

The goal is to progressively learn modern C++ idioms while staying constrained to **C++98** and the strict rules of the 42 Norm.

---

## Instructions

### Requirements

- A C++98-compatible compiler: `g++` or `clang++`
- `make` utility

### Compilation

Each exercise has its own `Makefile`. Navigate to the exercise directory and run:

```bash
cd CPP_XX/exYY
make
```

This compiles with the flags: `-Wall -Wextra -Werror -std=c++98`

### Execution

After compilation, run the resulting binary:

```bash
./executable_name
```

Refer to the subject PDF inside each module folder (`en.subject_CPPXX.pdf`) for the expected behavior and test cases.

### Cleanup

```bash
make clean    # remove object files
make fclean   # remove object files and binary
make re       # fclean + recompile
```