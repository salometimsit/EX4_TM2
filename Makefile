#//timsitmelosa@gmail.com
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -I. -O2

VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

TARGET = main
SRC = main.cpp
TEST_TARGET = test
TEST_SRC = Tests/Alltest.cpp

all: $(TARGET)


$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

valgrind: $(TEST_TARGET)
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./$(TEST_TARGET) 2>&1 | { egrep "lost| at " || true; }

clean:
	rm -f $(TARGET) $(TEST_TARGET)

.PHONY: all test clean valgrind
