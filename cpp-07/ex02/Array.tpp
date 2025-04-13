#ifndef ARRAY_TPP
#define ARRAY_TPP
#include "Array.hpp"
#include <exception>

template<typename T>
Array<T>::Array() : _amount(1) {
    this->_elements = new T[this->_amount];
}

template<typename T>
Array<T>::Array(unsigned int amount) : _amount(amount) {
    if (amount == 0) {
        throw std::invalid_argument("Size must be more than 0");
    }
    this->_elements = new T[this->_amount];
}

template<typename T>
Array<T>::Array(const Array& other) : _amount(other._amount) {
    this->_elements = new T[this->_amount];
    for (unsigned int i = 0; i < this->_amount; i++) {
        this->_elements[i] = other._elements[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator = (const Array& other) {
    if (this != &other) {
        delete[] this->_elements;
        this->_amount = other._amount;
        this->_elements = new T[this->_amount];
        for (unsigned int i = 0; i < this->_amount; i++) {
            this->_elements[i] = other._elements[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array() {
    delete[] this->_elements;
}

template<typename T>
unsigned int Array<T>::size(void) {
    return this->_amount;
}

template<typename T>
T& Array<T>::operator [] (unsigned int i) {
    if (i >= this->_amount) {
        throw std::out_of_range("Element is out of bounds.");
    }
    return this->_elements[i];
}

template<typename T>
const T& Array<T>::operator [] (unsigned int i) const {
    if (i >= this->_amount) {
        throw std::out_of_range("Element is out of bounds.");
    }
    return this->_elements[i];
}

#endif