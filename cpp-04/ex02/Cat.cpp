#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain("random cat thoughts")) {
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string ideas) : Animal("Cat"), _brain(new Brain(ideas)) {
    std::cout << "Cat modifed constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    this->_brain = other._brain;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << "Cat default destructor called" << std::endl;
}

Cat& Cat::operator = (const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        if (this->_brain) {
            delete this->_brain;
        }
        this->_brain = new Brain(*other._brain);
    }
    std::cout << "Cat deep copy assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "Cat makes sound: mew mew" << std::endl;
}
