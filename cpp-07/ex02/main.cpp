#include <iostream>
#include "Array.hpp"

int main() {
    try {
        Array<int> arr(5);

        for (unsigned int i = 0; i < arr.size(); i++) {
            arr[i] = i * 10;
        }

        std::cout << "Array contents: ";
        for (unsigned int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        Array<int> copyArr(arr);
        std::cout << "Copy contents: ";
        for (unsigned int i = 0; i < copyArr.size(); i++) {
            std::cout << copyArr[i] << " ";
        }
        std::cout << std::endl;

        Array<int> assignedArr;
        assignedArr = arr;

        std::cout << "Assigned contents: ";
        for (unsigned int i = 0; i < assignedArr.size(); i++) {
            std::cout << assignedArr[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Trying out-of-range access..." << std::endl;
        std::cout << arr[10] << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
