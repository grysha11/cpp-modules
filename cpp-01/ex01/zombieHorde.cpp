#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) {
        return NULL;
    }

    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; i++) {
        new (&horde[i]) Zombie(name + std::to_string(i + 1));
    }
    return horde;
}