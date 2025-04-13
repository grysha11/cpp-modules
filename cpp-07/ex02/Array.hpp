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
        Array();
        Array(unsigned int amount);
        Array(const Array& other);
        Array& operator = (const Array& other);
        ~Array();
        unsigned int size(void);
        T& operator [] (unsigned int i);
        const T& operator [] (unsigned int i) const;
};

#include "Array.tpp"
#endif