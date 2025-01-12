#include "Zombie.hpp"

std::string intToStr(int num) {
    std::string number;

    while (num > 0) {
        number.insert(number.begin(), '0' + (num % 10));
        num /= 10;
    }

    return number;
}

int main() {
    std::cout << YELLOW500 << "Testing zombies with manual deleting the memory using function newZombie" << std::endl;

    //Initialize the values and objects inside of a loop ususally not the best practise,
    //but for this testing I think I can do this.
    for (int i = 0; i < 10; i++) {
        std::string name = "test_zombie" + intToStr(i + 1);
        Zombie* test_zombie = newZombie(name);
        test_zombie->announce();
        delete test_zombie;
    }
    for (int i = 0; i < 10; i++) {
        std::string name = "test_zombie" + intToStr(i + 1);
        randomChump(name);
    }

    return 0;
}