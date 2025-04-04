#include "Serializer.hpp"
#include <iostream>

int main() {
    Data* test = new Data(10);

    std::cout << &test << " Original address of the data struct" << std::endl;
    uintptr_t testRaw = Serializer::serialize(test);
    std::cout << testRaw << " Serialized value of data ptr" << std::endl;
    Data* testCopy = Serializer::deserialize(testRaw);
    std::cout << &testCopy << " Deserialized value of data ptr" << std::endl;

    return 0;
}