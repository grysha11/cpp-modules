#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal"), _name("no_name") {
    std::cout << "WrongAnimal " << this->_name << " default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : _type("WrongAnimal"), _name(name) {
    (void)name;
    std::cout << "WrongAnimal " << this->_name << " modifed constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type), _name(other._name) {
    std::cout << "WrongAnimal " << this->_name << " copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal " << this->_name << " default destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& other) {
    if (this != &other) {
        this->_type = other._type;
        this->_name = other._name;
    }
    std::cout << "WrongAnimal " << this->_name << " copy assignment operator called" << std::endl;
    return *this;
}

void WrongAnimal::makeSound(void) const{
    std::cout << this->_name << ": Random animal sounds..." << std::endl;
}

const std::string& WrongAnimal::getType(void) const {
    return this->_type;
}

const std::string& WrongAnimal::getName(void) const {
    return this->_name;
}

void WrongAnimal::setName(std::string name) {
    this->_name = name;
}
