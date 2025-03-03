#include "Cat.hpp"

Cat::Cat() : Animal("no_name"), _brain(new Brain("random cat thoughts")) {
    this->_type = "Cat";
    std::cout << "Cat " << this->_name << " default constructor called" << std::endl;
}

Cat::Cat(std::string name) : Animal(name), _brain(new Brain("random cat thoughts")) {
    this->_type = "Cat";
    std::cout << "Cat " << this->_name << " modifed constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    this->_brain = new Brain(*other._brain);
    std::cout << "Cat " << this->_name << " deep copy constructor called" << std::endl;
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << "Cat " << this->_name << " default destructor called" << std::endl;
}

Cat& Cat::operator = (const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        if (this->_brain) {
            delete this->_brain;
        }
        this->_brain = new Brain(*other._brain);
    }
    std::cout << "Cat " << this->_name << " deep copy assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "Cat " << this->_name << " makes sound: mew mew" << std::endl;
}

std::string Cat::getIdea(int i) {
    return this->_brain->getIdea(i);
}

void Cat::setIdea(std::string idea) {
    this->_brain->setIdeas(idea);
}
