#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type("WrongAnimal") {
    (void)type;
    std::cout << "WrongAnimal modifed constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
    std::cout << "Wrongnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal default destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& other) {
    if (this != &other) {
        this->_type = other._type;
    }
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    return *this;
}

void WrongAnimal::makeSound(void) const{
    std::cout << "Random wrong animal sounds..." << std::endl;
}

const std::string& WrongAnimal::getType(void) const {
    return this->_type;
}
