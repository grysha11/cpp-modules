#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Incorrect amount of arguments" << std::endl;
        std::cerr << "'\tTry ./btc \"inputData\"" << std::endl;
        return 1;
    }
    try {
        const std::string file(av[1]);
        BitcoinExchange btc(file);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
