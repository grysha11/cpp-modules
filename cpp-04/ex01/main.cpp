#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

std::string intToStr(int num) {
    std::string number;

    while (num > 0) {
        number.insert(number.begin(), '0' + (num % 10));
        num /= 10;
    }

    return number;
}

void deepCopyTest(void) {
    //deep copy constructor test
    Cat* i = new Cat("test-copy-cat");
    Cat* j = new Cat(*i);

    std::cout << "1st cat is: " << i->getName() << " .2nd cat is: " << j->getName() << "\n1st thoughts are: " << i->getIdea(0) << "2nd thoughts are: " << j->getIdea(0) << std::endl;
    j->setIdea("new ideas");
    std::cout << "1st thoughts are: " << i->getIdea(0) << "2nd thoughts are: " << j->getIdea(0) << std::endl;

    //deep copy assignment test
    // Cat* i = new Cat("test-copy-cat");
    // Cat* j = new Cat();

    // *j = *i;

    // std::cout << "1st cat is: " << i->getName() << ". 2nd cat is: " << j->getName() << "\n1st thoughts are: " << i->getIdea(0) << " 2nd thoughts are: " << j->getIdea(0) << std::endl;
    // j->setIdea("new ideas");
    // std::cout << "1st thoughts are: " << i->getIdea(0) << " 2nd thoughts are: " << j->getIdea(0) << std::endl;
    delete i;
    delete j;
}

void arrTest(void) {
    Animal* animals[10];

    for (size_t i = 0; i < 10; i++) {
        if (i < 5) {
            animals[i] = new Cat("kitty cat" + intToStr(i));
        } else {
            animals[i] = new Dog("doggy dog" + intToStr(i));
        }
    }

    for (size_t i = 0; i < 10; i++) {
        animals[i]->makeSound();
    }

    for (size_t i = 0; i < 10; i++) {
        delete animals[i];
    }
}

int main() {
    deepCopyTest();

    return 0;
}
