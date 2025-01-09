#include <iostream>
#include <string>

int main(int ac, char **av) {
    if (ac < 2) {
        std::cout << "* LOUD AND UNBEREABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }

    for (int i = 1; i < ac; i++) {
        std::string str(av[i]);
        for (std::size_t i = 0; i < str.length(); i++) {
            str[i] = std::toupper(str[i]);
        }
        if (i != 1) {
            std::cout << " ";
        }
        std::cout << str;
    }
    std::cout << std::endl;

    return 0;
}
