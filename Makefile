#//timsitmelosa@gmail.com
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -I. -O2

VALGRIND_FLAGS =  --leak-check=full --show-leak-kinds=all --error-exitcode=99

TARGET = main
SRC = main.cpp
TEST_TARGET = test
TEST_SRC = Tests/Alltest.cpp

all: $(TARGET)


$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

valgrind: $(TEST_TARGET) $(TARGET)
	@echo "Running Valgrind on $(TEST_TARGET)..."
	@echo "Checking for memory leaks in $(TEST_TARGET)..."
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./$(TEST_TARGET)
	@echo ""
	@echo "Running Valgrind on $(TARGET)..."
	@echo "Checking for memory leaks in $(TARGET)..."
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./$(TARGET)


clean:
	rm -f $(TARGET) $(TEST_TARGET)

.PHONY: all test clean valgrind
