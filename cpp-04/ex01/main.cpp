#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
    Animal* animals[10];

    for (size_t i = 0; i < 10; i++) {
        if (i < 5) {
            animals[i] = new Cat("mewmewmewmew");
        } else {
            animals[i] = new Dog("wooofowofowofofwof");
        }
    }

    for (size_t i = 0; i < 10; i++) {
        animals[i]->makeSound();
    }

    for (size_t i = 0; i < 10; i++) {
        delete animals[i];
    }

    return 0;
}
