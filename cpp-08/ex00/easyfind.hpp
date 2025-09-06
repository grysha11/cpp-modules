#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& ints, int num) {
    typename T::iterator it;

    it = find(ints.begin(), ints.end(), num);
    if (it == ints.end()) {
        throw std::runtime_error("Number was not found");
    }
    return it;
}
