#ifndef SCALAR_CONVERTOR_HPP
#define SCALAR_CONVERTOR_HPP
#include <string>
#include <iostream>
#include <stdlib.h>

class ScalarConverter {
    private:
        ScalarConverter();

    public:
        static void convert(const std::string &literal);
};

#endif