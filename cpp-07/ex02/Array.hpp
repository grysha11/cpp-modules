#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <string>
#include <iostream>

template<typename T>
class Array {
    private:
        unsigned int _amount;
        T* _elements;
    public:
        Array() : _amount(0) {
            this->_elements = new T[0];
        }
        Array(unsigned int amount) : _amount(amount) {
            this->_elements = new[] T[this->_amount];
        }
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();
        T& operator[](unsigned int i);
        const T& operator[](unsigned int i) const;
};

#include "Array.tpp"
#endif