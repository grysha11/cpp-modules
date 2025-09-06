#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span {
    private:
        unsigned int _N;
        std::vector<int> _arr;
        Span& operator = (const Span& other);
    public:
        void addNumber(int num);
        void coolAddNumber(int size);
        int shortestSpan();
        int longestSpan();
        Span();
        Span(unsigned int N);
        ~Span();
};
