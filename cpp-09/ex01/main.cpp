#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: incorrect amount of arguments" << std::endl;
        std::cerr << "\tTry ./RPN \"expression\"" << std::endl;
        return 1;
    }
    try {
        std::string tokens = av[1];
        RPN rpn(tokens);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
