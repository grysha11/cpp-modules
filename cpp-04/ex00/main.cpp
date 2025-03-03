#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal("grisha");
    const Animal* j = new Dog("small tudor");
    const Animal* i = new Cat("big tudor");
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    const WrongAnimal* wrongMeta = new WrongAnimal("gosha");
    const WrongAnimal* wrongI = new WrongCat("andor");
    std::cout << wrongI->getType() << " " << std::endl;
    wrongI->makeSound();
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongI;

    return 0;
}