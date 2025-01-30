#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->_type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
    this->_type = "Dog";
    std::cout << "Dog modifed constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    this->_type = other._type;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
    Animal::~Animal();
    std::cout << "Dog default destructor called" << std::endl;
}

Dog& Dog::operator = (const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "Dog makes sound: woof woof" << std::endl;
}
