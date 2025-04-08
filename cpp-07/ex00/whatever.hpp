#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T& val1, T& val2) {
    T temp = val1;
    val1 = val2;
    val2 = temp;
}

template<typename T>
const T& min(T& val1, T& val2) {
    if (val1 > val2) {
        return val2;
    }
    return val1;
}

template<typename T>
const T& max(T& val1, T& val2) {
    if (val1 > val2) {
        return val1;
    }
    return val2;
}

#endif