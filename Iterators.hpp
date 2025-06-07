//timsitmelosa@gmail.com
#ifndef ITERATORS_HPP
#define ITERATORS_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <type_traits>
#include "MyContainer.hpp"

namespace Container {
    /**
        *@brief Class VectorIterator provides an iterator for a vector.
        * @tparam T Type of elements in the vector.
        * @returns An iterator that allows traversal of the elements in a vector.
        * This iterator can be used to iterate over the elements of a vector in a range-based for loop or with standard algorithms.
        * It provides the basic iterator functionality such as dereferencing, incrementing, and comparison.
        * It is designed to work with the `MyContainer` class, which uses a vector to store its elements.
        * The iterator can be used to access the elements in the order they were added to the `MyContainer`.
     */
   
    template<typename T>
    class VectorIterator {
    private:
        typename std::vector<T>::const_iterator it;
    public:
        explicit VectorIterator(typename std::vector<T>::const_iterator iter) : it(iter) {}
        const T& operator*() const { return *it; }
        VectorIterator& operator++() { ++it; return *this; }
        bool operator!=(const VectorIterator& other) const { return it != other.it; }
        bool operator==(const VectorIterator& other) const { return it == other.it; }
        VectorIterator operator++(int) { VectorIterator temp = *this; ++it; return temp; }

    };
    /**
        * @brief Class Order provides an iterator for the original order of elements in MyContainer.
        * @tparam T Type of elements in MyContainer.
        * @returns An iterator that allows traversal of the elements in the order they were added to MyContainer.
     */
    template<typename T>
    class Order {
    private:
        const std::vector<T>& data;
    public:
        explicit Order(const MyContainer<T>& c) : data(c.getData()) {}
        std::vector<T>& get_orderdata(){return data;}
        VectorIterator<T> begin() const { return VectorIterator<T>(data.begin()); }
        VectorIterator<T> end() const { return VectorIterator<T>(data.end()); }
        
    };
    /**
        * @brief Class ReverseOrder provides an iterator for the reverse order of elements in MyContainer.
        * @tparam T Type of elements in MyContainer.
        * @returns An iterator that allows traversal of the elements in reverse order.
     */
    template<typename T>
    class ReverseOrder {
    private:
        std::vector<T> reversed;
    public:
        explicit ReverseOrder(const MyContainer<T>& c) : reversed(c.getData()) {
            std::reverse(reversed.begin(), reversed.end());
        }
        std::vector<T> get_reverseorderdata(){return reversed;}
        VectorIterator<T> begin() const { return VectorIterator<T>(reversed.begin()); }
        VectorIterator<T> end() const { return VectorIterator<T>(reversed.end()); }

    };
    /**
        * @brief Class AscendingOrder provides an iterator for the elements in ascending order.
        * @tparam T Type of elements in MyContainer.
        * @returns An iterator that allows traversal of the elements in ascending order using sort method
     */
    template<typename T>
    class AscendingOrder {
        private:
        std::vector<T> sorted;
    public:
        explicit AscendingOrder(const MyContainer<T>& c) : sorted(c.getData()) {
            std::sort(sorted.begin(), sorted.end());
        }
        std::vector<T>& get_ascendingsorted(){return sorted;}
        VectorIterator<T> begin() const { return VectorIterator<T>(sorted.begin()); }
        VectorIterator<T> end() const { return VectorIterator<T>(sorted.end()); }
    };
    /**
        * @brief Class DescendingOrder provides an iterator for the elements in descending order.
        * @tparam T Type of elements in MyContainer.
        * @returns An iterator that allows traversal of the elements in descending order using sort method
     */
    template<typename T>
    class DescendingOrder {
    private:
        std::vector<T> sorted;
    public:
         explicit DescendingOrder(const MyContainer<T>& c) : sorted(c.getData()) {
            std::sort(sorted.begin(), sorted.end(), std::greater<T>());
        }
        std::vector<T>& get_descendngsorted(){return sorted;}
        VectorIterator<T> begin () const { return VectorIterator<T>(sorted.begin()); }
        VectorIterator<T> end() const { return VectorIterator<T>(sorted.end()); }
    
    };
    /**
        * @brief Class SideCrossOrder provides an iterator for the elements in a side-cross order- side cross means first 
        the smallest, then the largest, then the second smallest, then the second largest, etc
        * @tparam T Type of elements in MyContainer.
        * @returns An iterator that allows traversal of the elements in a side-cross order.
     */
    template<typename T>
    class SideCrossOrder {
    private:
        std::vector<T> crossed;
    public:
        SideCrossOrder(const MyContainer<T>& c) : crossed(c.getData()) {
            std::sort(crossed.begin(), crossed.end());
            std::vector<T> temp;
            size_t left = 0, right = crossed.size() - 1;
            while (left <= right) {
                if (left == right) {
                    temp.push_back(crossed[left]);
                } else {
                    temp.push_back(crossed[left]);
                    temp.push_back(crossed[right]);
                }
                left++;
                right--;
            }
            crossed = std::move(temp);
        }
        std::vector<T>& get_sidecrossed(){return crossed;}
        VectorIterator<T> begin() const { return VectorIterator<T>(crossed.begin()); }
        VectorIterator<T> end() const { return VectorIterator<T>(crossed.end()); }
    };

    /**
        * @brief Class MiddleOutOrder provides an iterator for the elements in a middle-out order- wich starts from the middle 
        and alternates between the left and right elements.
        * This means that if the container has an odd number of elements, it starts with the middle element and goes on 
        * If the container has an even number of elements, it starts with the middle two elements, then goes  on
        * @tparam T Type of elements in MyContainer.
        * @returns An iterator that allows traversal of the elements in a middle-out order.
     */
    template<typename T>
    class MiddleOutOrder {
    private:
        std::vector<T> ordered;
    public:
        MiddleOutOrder(const MyContainer<T>& c) {
            ordered = c.getData();
            std::vector<T> temp;
            int n = ordered.size();
            if (n == 0){
                return;
            }
            int mid = n / 2;  
            temp.push_back(ordered[mid]);  
            int left = mid - 1;   
            int right = mid + 1;  
            while (left >= 0 || right < n) {
                if (left >= 0) {
                    temp.push_back(ordered[left]);
                    left--;
                }
                if (right < n) {
                    temp.push_back(ordered[right]);
                    right++;
                }
            }

        ordered = std::move(temp);
    }
        std::vector<T>& get_middleout(){return ordered;}
        VectorIterator<T> begin() const { return VectorIterator<T>(ordered.begin()); }
        VectorIterator<T> end() const { return VectorIterator<T>(ordered.end()); }
     };

}
#endif 