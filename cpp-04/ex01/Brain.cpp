#include "Brain.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; i++) {
        this->_ideas[i] = "no ideas...";
    }
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(std::string idea) {
    for (int i = 0; i < 100; i++) {
        this->_ideas[i] = idea;
    }
    std::cout << "Brain modifed constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    if (this != &other) {
        for (size_t i = 0; i < 100; i++) {
            this->_ideas[i] = other._ideas[i];
        }
    }
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain default destructor called" << std::endl;
}

Brain& Brain::operator = (const Brain& other) {
    if (this != &other) {
        for (size_t i = 0; i < 100; i++) {
            this->_ideas[i] = other._ideas[i];
        }
    }
    std::cout << "Brain copy assignment operator called" << std::endl;
    return *this;
}

void Brain::setIdeas(std::string idea) {
    for (size_t i = 0; i < 100; i++) {
        this->_ideas[i] = idea;
    }
}

std::string Brain::getIdea(int i) const {
    if (i >= 0 && i < 100) {
        return this->_ideas[i];
    } else {
        return this->_ideas[0];
    }
}

