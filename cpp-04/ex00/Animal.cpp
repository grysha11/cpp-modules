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