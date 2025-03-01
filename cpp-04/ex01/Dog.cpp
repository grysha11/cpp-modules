#include "Dog.hpp"

Dog::Dog() : _brain(new Brain()) {
    this->_type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string ideas) : _brain(new Brain(ideas)) {
    this->_type = "Dog";
    std::cout << "Dog modifed constructor called" << std::endl;
}

Dog::Dog(const Dog& other) {
    this->_type = other._type;
    this->_brain = other._brain;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
    delete this->_brain;
    Animal::~Animal();
    std::cout << "Dog default destructor called" << std::endl;
}

Dog& Dog::operator = (const Dog& other) {
    if (this != &other) {
        if (this->_brain) {
            delete this->_brain;
        }
        this->_brain = new Brain(*other._brain);
    }
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "Dog makes sound: woof woof" << std::endl;
}
