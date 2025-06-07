### Iterators Understanding Assigment
### Email: timsitmelosa@gmail.com
### Classes and explanations
### `MyContainer.hpp`

- A templated class for storing elements (`MyContainer<T>`).
- Allows:
  - Adding elements
  - Removing elements
  - Accessing elements via `getData()`
- Includes overload for `operator<<` to enable easy printing.

### `Iterators.hpp`

Defines several classes that enable iteration over `MyContainer` elements in various logical orders:
- **VectorIterator**: is a custom iterator class that wraps a std::vector<T>::const_iterator to enable consistent iteration across all ordering classes. It supports dereferencing, incrementing, and comparison for use in loops.
- **Order**: Original insertion order.
- **ReverseOrder**: Reversed version of the insertion order.
- **AscendingOrder**: Sorted in increasing order.
- **DescendingOrder**: Sorted in decreasing order.
- **SideCrossOrder**: Alternates between smallest and biggest and then second smallest and second bigger etc.
- **MiddleOutOrder**: Starts from the middle, then alternates betwween left and right elements until the end.
Each class provides `begin()` and `end()` functions to traverse the data accordingly.

### `main.cpp`

- Demonstrates the functionality of the container and iterators.
- Includes both `int` and `std::string` types.
- Uses a generic `print()` function template to print elements using the provided iterators.

---

## ▶️ Build & Run

Make sure you have a C++ compiler and `make` installed.

### Build the project

```sh
make 
./main
```
### Run tests
```sh
make test
./test
```
### Run Valgrind
```sh
make Valgrind
```