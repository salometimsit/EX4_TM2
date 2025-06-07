//timsitmelosa@gmail.com
#include "doctest.h"
#include "MyContainer.hpp"
#include "Iterators.hpp"
#include <vector>
#include <string>
#include <algorithm>

TEST_CASE("Iterator copy and assignment") {
    MyContainer<int> container;
    container.addElement(1); 
    container.addElement(2); 
    container.addElement(3);
    SUBCASE("Order Iterator Copy") {
        Order<int> order(container);
        auto it1 = order.begin();
        auto it2 = it1;
        CHECK(*it1 == *it2);
        it1++;
        CHECK(*it1 != *it2);
        it2 = it1;
        CHECK(*it2 == *it1);
    }
    SUBCASE("ReverseOrder Iterator Copy") {
        ReverseOrder<int> reverse(container);
        auto it1 = reverse.begin();
        auto it2 = it1;
        CHECK(*it1 == *it2);
        it1++;
        CHECK(*it1 != *it2);
        it2 = it1;
        CHECK(*it2 == *it1);
    }
    SUBCASE("DescendingOrder Iterator Copy") {
        DescendingOrder<int> descending(container);
        auto it1 = descending.begin();
        auto it2 = it1;
        CHECK(*it1 == *it2);
        it1++;
        CHECK(*it1 != *it2);
        it2 = it1;
        CHECK(*it2 == *it1);
    }
    SUBCASE("AscendingOrder Iterator Copy") {
        AscendingOrder<int> ascending(container);
        auto it1 = ascending.begin();
        auto it2 = it1;
        CHECK(*it1 == *it2);
        it1++;
        CHECK(*it1 != *it2);
        it2 = it1;
        CHECK(*it2 == *it1);
    }
    SUBCASE("SideCrossOrder Iterator Copy") {
        SideCrossOrder<int> sidecross(container);
        auto it1 = sidecross.begin();
        auto it2 = it1;
        CHECK(*it1 == *it2);
        it1++;
        CHECK(*it1 != *it2);
        it2 = it1;
        CHECK(*it2 == *it1);
    }
    SUBCASE("MiddleOutOrder Iterator Copy") {
        MiddleOutOrder<int> middleout(container);
        auto it1 = middleout.begin();
        auto it2 = it1;
        CHECK(*it1 == *it2);
        it1++;
        CHECK(*it1 != *it2);
        it2 = it1;
        CHECK(*it2 == *it1);
    }
}

TEST_CASE("Order Iterator") {
    MyContainer<int> container;
    container.addElement(8);
    container.addElement(10);
    container.addElement(11);
    container.addElement(9); 
    Order<int> order(container);
    std::vector<int> result;
    for (auto it = order.begin(); it != order.end(); ++it) {
        result.push_back(*it);
    }
    std::vector<int> expected = {8, 10, 11, 9};
    CHECK(result == expected);
}

TEST_CASE("ReverseOrder Iterator") {
    MyContainer<int> container;
    container.addElement(8);
    container.addElement(10);
    container.addElement(11);
    container.addElement(9);
    ReverseOrder<int> reverse(container);
    std::vector<int> result;
    for(auto it = reverse.begin(); it != reverse.end(); ++it) {
        result.push_back(*it);
    }
    std::vector<int> expected = {9, 11, 10, 8};
    CHECK(result == expected);
}

TEST_CASE("AscendingOrder Iterator") {
    MyContainer<int> container;
    container.addElement(8);
    container.addElement(10);
    container.addElement(11);
    container.addElement(9);
    
    AscendingOrder<int> ascending(container);
    std::vector<int> result;
    for(auto it = ascending.begin(); it != ascending.end(); ++it) {
        result.push_back(*it);
    }
    std::vector<int> expected = {8, 9, 10, 11};
    CHECK(result == expected);
}

TEST_CASE("DescendingOrder Iterator") {
    MyContainer<int> container;
    container.addElement(8);
    container.addElement(10);
    container.addElement(11);
    container.addElement(9);
    
    DescendingOrder<int> descending(container);
    std::vector<int> result;
    for(auto it = descending.begin(); it != descending.end(); ++it) {
        result.push_back(*it);
    }
    std::vector<int> expected = {11, 10, 9, 8};
    CHECK(result == expected);
}

TEST_CASE("SideCrossOrder Iterator") {
    MyContainer<int> container;
    container.addElement(8);
    container.addElement(10);
    container.addElement(11);
    container.addElement(9);
    
    SideCrossOrder<int> sidecross(container);
    std::vector<int> result;
    for (auto it = sidecross.begin(); it != sidecross.end(); ++it) {
        result.push_back(*it);
    }
    std::vector<int> expected = {8, 11, 9, 10};
    CHECK(result == expected);
}

TEST_CASE("MiddleOutOrder Iterator") {
    SUBCASE("Odd number of elements") {
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);
        
        MiddleOutOrder<int> middleout(container);
        std::vector<int> result;
        for(auto it = middleout.begin(); it != middleout.end(); ++it) {
            result.push_back(*it);
        }
        std::vector<int> expected = {6, 15, 1, 7, 2};
        CHECK(result == expected);
    }
    
    SUBCASE("Even number of elements") {
        MyContainer<int> container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        
        MiddleOutOrder<int> middleout(container);
        std::vector<int> result;
        for(auto it = middleout.begin(); it != middleout.end(); ++it) {
            result.push_back(*it);
        }
        std::vector<int> expected = {3, 2, 4, 1};
        CHECK(result == expected);
    }
}

TEST_CASE("Iterator Tests with Strings") {
    MyContainer<std::string> container;
    container.addElement("banana");
    container.addElement("apple");
    container.addElement("cherry");
    container.addElement("date");
    SUBCASE("AscendingOrder with strings") {
        AscendingOrder<std::string> ascending(container);
        std::vector<std::string> result;
        for (auto it = ascending.begin(); it != ascending.end(); ++it) {
            result.push_back(*it);
        }
        std::vector<std::string> expected = {"apple", "banana", "cherry", "date"};
        CHECK(result == expected);
    }
    
    SUBCASE("DescendingOrder with strings") {
        DescendingOrder<std::string> descending(container);
        std::vector<std::string> result;
        for (auto it = descending.begin(); it != descending.end(); ++it) {
            result.push_back(*it);
        }
        std::vector<std::string> expected = {"date", "cherry", "banana", "apple"};
        CHECK(result == expected);
    }
    
    SUBCASE("MiddleOutOrder with strings") {
        MiddleOutOrder<std::string> middleout(container);
        std::vector<std::string> result;
        for (auto it = middleout.begin(); it != middleout.end(); ++it) {
            result.push_back(*it);
        }
        std::vector<std::string> expected = {"cherry", "apple", "date", "banana"};
        CHECK(result == expected);
    }
}

TEST_CASE("Edge Cases") {
    SUBCASE("Empty container with iterators") {
        MyContainer<int> empty_container;
        
        Order<int> order(empty_container);
        CHECK(order.begin() == order.end());
        
        AscendingOrder<int> ascending(empty_container);
        CHECK(ascending.begin() == ascending.end());
        
        MiddleOutOrder<int> middleout(empty_container);
        CHECK(middleout.begin() == middleout.end());
    }
    
    SUBCASE("Single element container") {
        MyContainer<int> single_container;
        single_container.addElement(42);
        
        MiddleOutOrder<int> middleout(single_container);
        std::vector<int> result;
        for(auto it = middleout.begin(); it != middleout.end(); ++it) {
            result.push_back(*it);
        }
        std::vector<int> expected = {42};
        CHECK(result == expected);
    }
    
    SUBCASE("Two element container") {
        MyContainer<int> two_container;
        two_container.addElement(10);
        two_container.addElement(20);
        
        MiddleOutOrder<int> middleout(two_container);
        std::vector<int> result;
        for(auto it = middleout.begin(); it != middleout.end(); ++it) {
            result.push_back(*it);
        }
        std::vector<int> expected = {20, 10};
        CHECK(result == expected);
    }
}
TEST_CASE("Iterators with char type") {
    Container::MyContainer<char> container;
    container.addElement('d');
    container.addElement('a');
    container.addElement('c');
    container.addElement('b');

    SUBCASE("AscendingOrder with char") {
        Container::AscendingOrder<char> asc(container);
        std::vector<char> result;
        for (auto it = asc.begin(); it != asc.end(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == std::vector<char>{'a', 'b', 'c', 'd'});
    }

    SUBCASE("SideCrossOrder with char") {
    Container::SideCrossOrder<char> cross(container);
    std::vector<char> result;
    for (auto it = cross.begin(); it != cross.end(); ++it) {
        result.push_back(*it);
    }
    // Sorted: a, b, c, d -> cross: a, d, b, c
    CHECK(result == std::vector<char>{'a', 'd', 'b', 'c'});
    }
}
TEST_CASE("Iterators with double type") {
    Container::MyContainer<double> container;
    container.addElement(3.14);
    container.addElement(2.71);
    container.addElement(-1.0);
    container.addElement(0.0);
    container.addElement(1.618);

    SUBCASE("AscendingOrder with double") {
        Container::AscendingOrder<double> asc(container);
        std::vector<double> result;
        for (auto it = asc.begin(); it != asc.end(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == std::vector<double>{-1.0, 0.0, 1.618, 2.71, 3.14});
    }

    SUBCASE("MiddleOutOrder with double") {
        Container::MiddleOutOrder<double> mid(container);
        std::vector<double> result;
        for (auto it = mid.begin(); it != mid.end(); ++it) {
            result.push_back(*it);
        }
        CHECK(result.size() == 5);
    }
}


