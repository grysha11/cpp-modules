#include <iostream>
#include <string>

int main(int ac, char **av) {
    if (ac < 2) {
        std::cout << "* LOUD AND UNBEREABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }

    for (size_t i = 1; av[i]; i++) {
        for (size_t j = 0; av[i][j]; j++) {
            if (islower(av[i][j])) {
                std::cout << (char)toupper(av[i][j]);
            } else {
                std::cout << av[i][j];
            }
        }
    }
    std::cout << std::endl;

    return 0;
}