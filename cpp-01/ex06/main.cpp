#include "Harl.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Incorrect amount of arguments passed to the program\tTry ./executable OPTION" << std::endl;
        return 1;
    }
    std::string input(av[1]);
    Harl hihiharl;
    hihiharl.harlFilter(input);
    return 0;
}
