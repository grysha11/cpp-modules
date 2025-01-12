#include "Zombie.hpp"

static std::string intToStr(int num) {
    std::string number;

    while (num > 0) {
        number.insert(number.begin(), '0' + (num % 10));
        num /= 10;
    }

    return number;
}

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) {
        return NULL;
    }

    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; i++) {
        new (&horde[i]) Zombie();
        horde[i].setName(name + intToStr(i + 1));
    }
    return horde;
}