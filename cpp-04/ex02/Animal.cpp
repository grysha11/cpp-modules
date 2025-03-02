#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type("Animal") {
    (void)type;
    std::cout << "Animal modifed constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal default destructor called" << std::endl;
}

Animal& Animal::operator = (const Animal& other) {
    if (this != &other) {
        this->_type = other._type;
    }
    std::cout << "Animal copy assignment operator called" << std::endl;
    return *this;
}

void Animal::makeSound(void) const{
    std::cout << "Random animal sounds..." << std::endl;
}

const std::string& Animal::getType(void) const {
    return this->_type;
}
