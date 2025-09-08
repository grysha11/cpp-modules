#pragma once
#include <algorithm>
#include <stack>
#include <deque>
#include <iostream>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
    public:
        MutantStack();
        MutantStack(const MutantStack& other);
        ~MutantStack();
        MutantStack& operator = (const MutantStack& other);
        typedef typename Container::iterator iterator;
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"