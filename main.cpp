//timsitmelosa@gmail.com
#include "MyContainer.hpp"
#include "Iterators.hpp"
#include <iostream>

template<typename Iterator>
void print(Iterator begin, Iterator end, std::ostream& os = std::cout) {
    bool first = true;
    for (auto it = begin; it != end; ++it) {
        if (!first) os << ", ";
        os << *it;
        first = false;
    }
    os << '\n';
}

int main() {
    using namespace Container;

    MyContainer<int> c;
    c.addElement(7); c.addElement(15); c.addElement(6); c.addElement(1); c.addElement(2);

    std::cout << "Original: " << c << "\n";
    AscendingOrder<int> asc(c);
    std::cout << "Ascending Order: ";
    print(asc.begin_ascending_order(), asc.end_ascending_order(), std::cout);
    
    DescendingOrder<int> desc(c);
    std::cout << "Descending Order: ";
    print(desc.begin_descending_order(), desc.end_descending_order(), std::cout);

    SideCrossOrder<int> cross(c);   
    std::cout << "Side Cross Order: ";
    print(cross.begin_side_cross_order(), cross.end_side_cross_order(), std::cout);

    ReverseOrder<int> rev(c);
    std::cout << "Reverse Order: ";
    print(rev.begin_reverse_order(), rev.end_reverse_order(), std::cout);

    Order<int> ord(c);
    std::cout << "Order: ";
    print(ord.begin_order(), ord.end_order(), std::cout);

    MiddleOutOrder<int> mid(c);
    std::cout << "Middle Out Order: ";
    print(mid.begin_middle_out_order(), mid.end_middle_out_order(), std::cout);


    MyContainer<std::string> sc;
    sc.addElement("banana");
    sc.addElement("apple");
    sc.addElement("cherry");
    sc.addElement("date");
    sc.addElement("elderberry");

    std::cout << "Original: " << sc << "\n";

    AscendingOrder<std::string> asc_s(sc);

    std::cout << "Ascending Order: ";
    print(asc_s.begin_ascending_order(), asc_s.end_ascending_order(), std::cout);

    DescendingOrder<std::string> desc_s(sc);
    std::cout << "Descending Order: ";
    print(desc_s.begin_descending_order(), desc_s.end_descending_order(), std::cout);

    SideCrossOrder<std::string> cross_s(sc);
    std::cout << "Side Cross Order: ";
    print(cross_s.begin_side_cross_order(), cross_s.end_side_cross_order(), std::cout);

    ReverseOrder<std::string> rev_s(sc);
    std::cout << "Reverse Order: ";
    print(rev_s.begin_reverse_order(), rev_s.end_reverse_order(), std::cout);

    Order<std::string> ord_s(sc);
    std::cout << "Order: ";
    print(ord_s.begin_order(), ord_s.end_order(), std::cout);

    MiddleOutOrder<std::string> mid_s(sc);
    std::cout << "Middle Out Order: ";
    print(mid_s.begin_middle_out_order(), mid_s.end_middle_out_order(), std::cout);

    Container::MyContainer<char> container;
    container.addElement('d');
    container.addElement('a');
    container.addElement('c');
    container.addElement('b');
    std::cout << "Original: " << container << "\n";
    AscendingOrder<char> asc_c(container);
    std::cout << "Ascending Order: ";
    print(asc_c.begin_ascending_order(), asc_c.end_ascending_order(), std::cout);
    DescendingOrder<char> desc_c(container);
    std::cout << "Descending Order: ";
    print(desc_c.begin_descending_order(), desc_c.end_descending_order(), std::cout);
    SideCrossOrder<char> cross_c(container);
    std::cout << "Side Cross Order: ";
    print(cross_c.begin_side_cross_order(), cross_c.end_side_cross_order(), std::cout);
    ReverseOrder<char> rev_c(container);
    std::cout << "Reverse Order: ";
    print(rev_c.begin_reverse_order(), rev_c.end_reverse_order(), std::cout);
    Order<char> ord_c(container);
    std::cout << "Order: ";
    print(ord_c.begin_order(), ord_c.end_order(), std::cout);
    MiddleOutOrder<char> mid_c(container);
    std::cout << "Middle Out Order: ";
    print(mid_c.begin_middle_out_order(), mid_c.end_middle_out_order(), std::cout);
    
    return 0;
}
