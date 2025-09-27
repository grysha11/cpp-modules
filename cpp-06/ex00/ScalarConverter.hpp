#ifndef SCALAR_CONVERTOR_HPP
#define SCALAR_CONVERTOR_HPP
#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <limits.h>
#include <stdexcept>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        static void printChar(double d);
        static void printInt(double d);
        static void printFloat(double d);
        static void printDouble(double d);
        static void printImpossible();
        static void catchImpossible(const std::string& literal);
    public:
        static void convert(const std::string& literal);
};

#endif