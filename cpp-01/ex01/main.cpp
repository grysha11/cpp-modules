#include "Zombie.hpp"

int main() {
    const int N = 10;

    Zombie* new_horde = zombieHorde(N, "test_zombie");
    if (!new_horde) {
        std::cout << RED500 << "Error during allocation of the new horde" << std::endl;
        return (0);
    }
    for (int i = 0; i < N; i++) {
        new_horde[i].announce();
    }

    delete[] new_horde;
    return 0;
}