#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    this->_type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string name) : WrongAnimal(name) {
    this->_type = "WrongCat";
    std::cout << "WrongCat modifed constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    this->_type = other._type;
    this->_name = other._name;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    WrongAnimal::~WrongAnimal();
    std::cout << "WrongCat default destructor called" << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    return *this;
}

void WrongCat::makeSound(void) const {
    std::cout << "WrongCat makes sound: mew mew" << std::endl;
}
