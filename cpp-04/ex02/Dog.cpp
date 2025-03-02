#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string ideas) : Animal("Dog"), _brain(new Brain(ideas)) {
    std::cout << "Dog modifed constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    this->_brain = other._brain;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog default destructor called" << std::endl;
}

Dog& Dog::operator = (const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
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
