#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->_type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
    this->_type = "Cat";
    std::cout << "Cat modifed constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    this->_type = other._type;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
    Animal::~Animal();
    std::cout << "Cat default destructor called" << std::endl;
}

Cat& Cat::operator = (const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "Cat makes sound: mew mew" << std::endl;
}
