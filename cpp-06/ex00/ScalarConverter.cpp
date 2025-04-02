#include "ScalarConverter.hpp"

char ScalarConverter::convChar(const std::string& input) {
    std::stringstream ss(input);
    int i;
    if (!(ss >> i) || !ss.eof()) {
        throw std::invalid_argument("Invalid argument");
    }
    if (i < 32 || i > 126) {
        throw std::invalid_argument("Non-displayable");
    }
    char c = i;
    return c;
}

float ScalarConverter::convFloat(const std::string& input) {
    std::stringstream ss(input);
    float f;
    if (!(ss >> f) || !ss.eof()) {
        throw std::invalid_argument("Invalid argument");
    }
    return f;
}

double ScalarConverter::convDouble(const std::string& input) {
    std::stringstream ss(input);
    double d;
    if (!(ss >> d) || !ss.eof()) {
        throw std::invalid_argument("Invalid argument");
    }
    return d;
}

bool ScalarConverter::isInt(const std::string& input) {
    int i = 0;

    if (input[i] == '-' || input[i] == '+') i++;
    for (; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    return true;
}

void ScalarConverter::printChar(const std::string& input) {
    std::cout << "char: ";
    try {
        if (input.length() == 1 && !isdigit(input[0])) {
            std::cout << "'" << input[0] << "'" << std::endl;
        }
        char c = convChar(input);
        std::cout << "'" << input[0] << "'" << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void ScalarConverter::printInt(const std::string& input) {
    std::cout << "int: ";
    if (!isInt(input)) {
        std::cout << "Impossible" << std::endl;
        return;
    }
    try {
        int i = std::atoi(input.c_str());
        std::cout << i << std::endl;
    } catch (std::exception& e) {
        std::cout << "Impossible" << std::endl;
    }
}

void ScalarConverter::printFloat(const std::string& input) {
    std::cout << "float: ";
    try {
        float f = convFloat(input);
        std::cout << f << "f" << std::endl;

    } catch (std::exception& e) {
        std::cout << "Impossible" << std::endl;
    }
}

void ScalarConverter::printDouble(const std::string& input) {
    std::cout << "double: ";
    try {
        double d = convDouble(input);
        std::cout << d << std::endl;
    } catch (std::exception& e) {
        std::cout << "Impossible" << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal) {
    printChar(literal);
    printInt(literal);
    printFloat(literal);
    printDouble(literal);
}
