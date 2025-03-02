#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
    // Animal* j = new Animal("animal");

    Animal* j = new Cat("some stuff");
    j->makeSound();

    delete j;

    return 0;
}
