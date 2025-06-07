//timsitmelosa@gmail.com
#ifndef MYCONTAINER_HPP
#define MYCONTAINER_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <type_traits>
namespace Container {
    /**
        * @brief Class MyContainer provides a container for storing elements of type T.
        * It supports adding elements, removing elements, and provides an iterator interface.
        * @tparam T Type of elements stored in the container, default is int.
     */
    template<typename T=int>
    class MyContainer{
        private:
            std::vector<T> data;
        public:
            MyContainer() = default;
            /**
            * @brief Adds an element to the container.
            * @param val The value to be added to the container.
            * @throws std::runtime_error if the value already exists in the container.
             */
            void addElement(const T& val){
                data.push_back(val);
            }
            /**
            * @brief Removes an element from the container.
            * @param val The value to be removed from the container.
            * @throws std::runtime_error if the value does not exist in the container.
            */
            void remove(const T& val){
                auto it = std::remove(data.begin(), data.end(), val);
                if (it != data.end()) {
                    data.erase(it, data.end());
                } else {
                    throw std::runtime_error("Value not found in container");
                }
            }
            /**
            * @brief Returns the number of elements in the container.
            * @return The size of the container.
            */
            size_t size() const{
                return data.size();
            }
            /**
            * @brief Returns a constant reference to the data stored in the container.
            * @return A constant reference to the vector containing the elements.
            */
            const std::vector<T>& getData() const {
                return data;
            }
            /**
            * @brief Returns a reference to the data stored in the container.
            * @return A reference to the vector containing the elements.
            */
            friend std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container){
                os << "{ ";
                bool first = true;
                for (const auto& elem : container.data) {
                    if(!first) os << ", ";
                    os << elem << " ";
                    first = false;
                }
                os << "}";
                return os;
            }
            
    };
}
#endif