//timsitmelosa@gmail.com
#include "MyContainer.hpp"
#include "Iterators.hpp"
#include <iostream>

using namespace Container;

int main() {
    MyContainer<int> c;
    c.addElement(7); c.addElement(15); c.addElement(6); c.addElement(1); c.addElement(2);

    std::cout << "Original: " << c << "\n";

    std::cout << "Ascending Order: ";
    for (const auto& x : AscendingOrder<int>(c)) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Descending Order: ";
    for (const auto& x : DescendingOrder<int>(c)) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Side Cross Order: ";
    for (const auto& x : SideCrossOrder<int>(c)) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Reverse Order: ";
    for (const auto& x : ReverseOrder<int>(c)) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Order: ";
    for (const auto& x : Order<int>(c)) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Middle Out Order: ";
    for (const auto& x : MiddleOutOrder<int>(c)) std::cout << x << " ";
    std::cout << "\n";

    MyContainer<std::string> sc;
    sc.addElement("banana");
    sc.addElement("apple");
    sc.addElement("cherry");
    sc.addElement("date");
    sc.addElement("elderberry");

    std::cout << "Original: " << sc << "\n";

    std::cout << "Ascending Order: ";
    for (const auto& x : AscendingOrder<std::string>(sc)) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Descending Order: ";
    for (const auto& x : DescendingOrder<std::string>(sc)) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Side Cross Order: ";
    for (const auto& x : SideCrossOrder<std::string>(sc)) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Reverse Order: ";
    for (const auto& x : ReverseOrder<std::string>(sc)) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Order: ";
    for (const auto& x : Order<std::string>(sc)) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Middle Out Order: ";
    for (const auto& x : MiddleOutOrder<std::string>(sc)) std::cout << x << " ";
    std::cout << "\n";

    MyContainer<char> container;
    container.addElement('d');
    container.addElement('a');
    container.addElement('c');
    container.addElement('b');

    std::cout << "Original: " << container << "\n";

    std::cout << "Ascending Order: ";
    for (const auto& x : AscendingOrder<char>(container)) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Descending Order: ";
    for (const auto& x : DescendingOrder<char>(container)) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Side Cross Order: ";
    for (const auto& x : SideCrossOrder<char>(container)) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Reverse Order: ";
    for (const auto& x : ReverseOrder<char>(container)) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Order: ";
    for (const auto& x : Order<char>(container)) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Middle Out Order: ";
    for (const auto& x : MiddleOutOrder<char>(container)) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
