#include "Span.hpp"

void Span::addNumber(int num) {
    if (this->_arr.size() == this->_N) {
        throw std::out_of_range("The array is full");
    }
    this->_arr.push_back(num);
}

int Span::shortestSpan() {
    if (this->_arr.size() < 2) {
        throw std::runtime_error("Array must contain at least 2 elements");
    }

    std::sort(this->_arr.begin(), this->_arr.end());
    int span = std::numeric_limits<int>::max();
    for (std::vector<int>::iterator it = this->_arr.begin(); it + 1 != this->_arr.end(); ++it) {
        int sspan = *(it + 1) - *it;
        if (sspan < span) {
            span = sspan;
        }
    }

    return span;
}

void Span::coolAddNumber(int size) {
    if (this->_arr.size() + size > this->_N) {
        throw std::out_of_range("The array is full or coolAddNumber is too big size");
    }

    for (int i = 0; i < size; i++) {
        this->_arr.push_back(i);
    }
}

int Span::longestSpan() {
    if (this->_arr.size() < 2) {
        throw std::runtime_error("Array must contain at least 2 elements");
    }

    int min = *std::min_element(this->_arr.begin(), this->_arr.end());
    int max = *std::max_element(this->_arr.begin(), this->_arr.end());

    return max - min;
}

Span::Span() : _N(1) {

}

Span::Span(unsigned int N) : _N(N) {

}

Span::~Span() {

}
