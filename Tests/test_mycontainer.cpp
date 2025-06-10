//timsitmelosa@gmail.com
#include "doctest.h"
#include "MyContainer.hpp"
#include "Iterators.hpp"
#include <vector>
#include <string>
#include <algorithm>

using namespace Container;

// MyContainer Tests
TEST_CASE("MyContainer - Basic Operations") {
    MyContainer<int> container;
    
    SUBCASE("Empty container") {
        CHECK(container.size() == 0);
        CHECK(container.getData().empty());
    }
    
    SUBCASE("Adding elements") {
        container.addElement(10);
        container.addElement(20);
        container.addElement(30);
        
        CHECK(container.size() == 3);
        auto data = container.getData();
        CHECK(data[0] == 10);
        CHECK(data[1] == 20);
        CHECK(data[2] == 30);
    }
    
    SUBCASE("Removing elements") {
        container.addElement(10);
        container.addElement(20);
        container.addElement(30);
        container.addElement(20); // duplicate
        
        container.remove(20);
        CHECK(container.size() == 2);
        auto data = container.getData();
        CHECK(data[0] == 10);
        CHECK(data[1] == 30);
        
    }
    
    SUBCASE("Remove non-existent element throws exception") {
        container.addElement(10);
        CHECK_THROWS_AS(container.remove(99), std::runtime_error);
    }
    
    
}

TEST_CASE("MyContainer - String Operations") {
    MyContainer<std::string> container;
    
    container.addElement("hello");
    container.addElement("world");
    container.addElement("test");
    
    CHECK(container.size() == 3);
    auto data = container.getData();
    CHECK(data[0] == "hello");
    CHECK(data[1] == "world");
    CHECK(data[2] == "test");
    
    container.remove("world");
    CHECK(container.size() == 2);
    data = container.getData();
    CHECK(data[0] == "hello");
    CHECK(data[1] == "test");
}