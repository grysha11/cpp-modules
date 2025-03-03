#include "Animal.hpp"

Animal::Animal() : _type("Animal"), _name("no_name") {
    std::cout << "Animal " << this->_name << " default constructor called" << std::endl;
}

Animal::Animal(std::string name) : _type("Animal"), _name(name) {
    (void)name;
    std::cout << "Animal " << this->_name << " modifed constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type), _name(other._name) {
    std::cout << "Animal " << this->_name << " copy constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal " << this->_name << " default destructor called" << std::endl;
}

Animal& Animal::operator = (const Animal& other) {
    if (this != &other) {
        this->_type = other._type;
        this->_name = other._name;
    }
    std::cout << "Animal " << this->_name << " copy assignment operator called" << std::endl;
    return *this;
}

void Animal::makeSound(void) const{
    std::cout << this->_name << ": Random animal sounds..." << std::endl;
}

const std::string& Animal::getType(void) const {
    return this->_type;
}

const std::string& Animal::getName(void) const {
    return this->_name;
}

void Animal::setName(std::string name) {
    this->_name = name;
}
