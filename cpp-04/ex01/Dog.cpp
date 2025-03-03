#include "Dog.hpp"

Dog::Dog() : Animal("no_name"), _brain(new Brain("random dog thoughts")) {
    this->_type = "Dog";
    std::cout << "Dog " << this->_name << " default constructor called" << std::endl;
}

Dog::Dog(std::string name) : Animal(name), _brain(new Brain("random dog thoughts")) {
    this->_type = "Dog";
    std::cout << "Dog " << this->_name << " modifed constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    this->_brain = new Brain(*other._brain);
    std::cout << "Dog " << this->_name << " deep copy constructor called" << std::endl;
}

Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog " << this->_name << " default destructor called" << std::endl;
}

Dog& Dog::operator = (const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        if (this->_brain) {
            delete this->_brain;
        }
        this->_brain = new Brain(*other._brain);
    }
    std::cout << "Dog " << this->_name << " deep copy assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "Dog " << this->_name << " makes sound: mew mew" << std::endl;
}

std::string Dog::getIdea(int i) {
    return this->_brain->getIdea(i);
}

void Dog::setIdea(std::string idea) {
    this->_brain->setIdeas(idea);
}