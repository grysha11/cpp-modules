#include "iter.hpp"
#include <iostream>

void incOne(int& i) {
    i += 1;
}

int main(void) {
    int arr[3] = {1, 2, 3};
    std::cout << "Original array: ";
    for (int i = 0; i < 3; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    iter(arr, 3, incOne);
    std::cout << "Modifed array after iteration: ";
    for (int i = 0; i < 3; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}