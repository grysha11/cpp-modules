#include "ScalarConverter.hpp"

bool isChar(const std::string& input) {
    if (input.size() == 1 && !isdigit(input[0])) {
        return true;
    }
    return false;
}

bool isInt(const std::string& input) {
    size_t i = 0;

    if (input[i] == '+' || input[i] == '+') i++;

    for (; i < input.size(); i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }

    return true;
}

bool isFloat(const std::string& input) {
    if (input == "nanf" || input == "+inff" || input == "-inff") return true;

    size_t i = 0, dotC = 0, eC = 0;

    if (input[i] == '+' || input[i] == '-') i++;

    for (; i < input.length(); i++) {
        if (input[i] == '.' && i != input.length() - 1 && i != 0 && (i == 1 && (input[0] != '-' || input[1] != '+'))) dotC++;
        else if (input[i] == 'e' || input[i] == 'E') {
            eC++;
            if (eC > 1 || i == 0 || i == input.length() - 1) return false;
            if (input[i + 1] == '-' || input[i] == '+') i++;
        } else if (input[i] == 'f' && i == input.length() - 1) i++;
        else if (!isdigit(input[i])) return false;
    }
    return dotC <= 1 && eC <= 1;
}

bool isDouble(const std::string& input) {
    if (input == "nan" || input == "+inf" || input == "-inf") return true;

    size_t i = 0, dotC = 0, eC = 0;

    if (input[i] == '+' || input[i] == '-') i++;

    for (; i < input.length(); i++) {
        if (input[i] == '.' && i != input.length() - 1 && i != 0 && (i == 1 && (input[0] != '-' || input[1] != '+'))) dotC++;
        else if (input[i] == 'e' || input[i] == 'E') {
            eC++;
            if (eC > 1 || i == 0 || i == input.length() - 1) return false;
            if (input[i + 1] == '-' || input[i] == '+') i++;
        }
        else if (!isdigit(input[i])) return false;
    }
    return dotC <= 1 && eC <= 1;
}

void ScalarConverter::convert(const std::string& literal) {
    double num;

    
}
