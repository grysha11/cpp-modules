#ifndef SCALAR_CONVERTOR_HPP
#define SCALAR_CONVERTOR_HPP
#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <limits.h>

class ScalarConverter {
    private:
        ScalarConverter();
        static char convChar(const std::string& input);
        static float convFloat(const std::string& input);
        static double convDouble(const std::string& input);
        static bool isInt(const std::string& input);
        static void printChar(const std::string& input);
        static void printInt(const std::string& input);
        static void printFloat(const std::string& input);
        static void printDouble(const std::string& input);
    public:
        static void convert(const std::string &literal);
};

#endif