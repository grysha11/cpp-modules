#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cctype>

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {

}

void ScalarConverter::printChar(double d) {
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()) {
        std::cout << "impossible" << std::endl;
    } else if (!std::isprint(static_cast<char>(d))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    }
}

void ScalarConverter::printInt(double d) {
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(d) << std::endl;
    }
}

void ScalarConverter::printFloat(double d) {
    std::cout << "float: " << static_cast<float>(d);
    double intPart;
    if (std::modf(d, &intPart) == 0.0 && !std::isinf(d)) {
        std::cout << ".0";
    }
    std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
    std::cout << "double: " << d;
    double intPart;
    if (std::modf(d, &intPart) == 0.0 && !std::isinf(d)) {
        std::cout << ".0";
    }
    std::cout << std::endl;
}

void ScalarConverter::printImpossible() {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::catchImpossible(const std::string& literal) {
    if (literal.empty()) {
        printImpossible();
        throw std::runtime_error("");
    }

    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        throw std::runtime_error("");
    }

    char* pEnd = NULL;
    double d = std::strtod(literal.c_str(), &pEnd);

    std::string endStr(pEnd);
    if (endStr != "" && endStr != "f") {
        printImpossible();
        throw std::runtime_error("");
    }

    if (d == 0.0 && literal[0] != '0' && literal[0] != '+' && literal[0] != '-') {
        printImpossible();
        throw std::runtime_error("");
    }
}

void ScalarConverter::convert(const std::string& literal) {
    try {
        catchImpossible(literal);

        char* pEnd = NULL;
        double d = std::strtod(literal.c_str(), &pEnd);

        printChar(d);
        printInt(d);
        printFloat(d);
        printDouble(d);
    } catch (std::exception& e) {
        return;
    }
}
