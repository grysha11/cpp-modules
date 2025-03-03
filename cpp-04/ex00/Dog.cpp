#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->_type = "Dog";
    std::cout << "Dog " << this->_name << " default constructor called" << std::endl;
}

Dog::Dog(std::string name) : Animal(name) {
    this->_type = "Dog";
    std::cout << "Dog " << this->_name << " modifed constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    this->_type = other._type;
    this->_name = other._name;
    std::cout << "Dog " << this->_name << " copy constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog " << this->_name << " default destructor called" << std::endl;
}

Dog& Dog::operator = (const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Dog " << this->_name << " copy assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "Dog " << this->_name << " makes sound: woof woof" << std::endl;
}
