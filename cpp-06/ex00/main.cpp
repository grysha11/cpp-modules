#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    if (ac == 2) {
        ScalarConvertor::convert(av[1]);
    }
    std::cout << "Incorrect amount of args" << std::endl;

    return 0;
}