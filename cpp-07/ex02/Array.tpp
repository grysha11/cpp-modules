#include "Array.hpp"
#include <exception>

template<typename T>
T& Array<T>::operator[](unsigned int i) {
    if (i >= this->_amount) {
        throw std::out_of_range("Element is out of bounds.");
    }
    return this->_elements[i];
}

template<typename T>
const T& Array<T>::operator[](unsigned int i) const {
    if (i >= this->_amount) {
        throw std::out_of_range("Element is out of bounds.");
    }
    return this->_elements[i];
}
