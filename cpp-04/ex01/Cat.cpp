#include "Cat.hpp"

Cat::Cat() : _brain(new Brain("random cat thoughts")) {
    this->_type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string ideas) : _brain(new Brain(ideas)) {
    this->_type = "Cat";
    std::cout << "Cat modifed constructor called" << std::endl;
}

Cat::Cat(const Cat& other) {
    this->_type = other._type;
    this->_brain = other._brain;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
    delete this->_brain;
    Animal::~Animal();
    std::cout << "Cat default destructor called" << std::endl;
}

Cat& Cat::operator = (const Cat& other) {
    if (this != &other) {
        this->_type = other._type;
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
