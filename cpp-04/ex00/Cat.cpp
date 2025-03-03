#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->_type = "Cat";
    std::cout << "Cat " << this->_name << " default constructor called" << std::endl;
}

Cat::Cat(std::string name) : Animal(name) {
    this->_type = "Cat";
    std::cout << "Cat " << this->_name << " modifed constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    this->_type = other._type;
    std::cout << "Cat " << this->_name << " copy constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat " << this->_name << " default destructor called" << std::endl;
}

Cat& Cat::operator = (const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Cat " << this->_name << " copy assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "Cat " << this->_name << " makes sound: mew mew" << std::endl;
}
