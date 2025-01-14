#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << GREEN500 << "Unknown Zombie constructor called" << RESET << std::endl;
}

Zombie::Zombie(std::string name) {
    this->_name = name;
    std::cout << GREEN500 << this->_name << ":Zombie constructor called" << RESET << std::endl;
}

Zombie::~Zombie() {
    std::cout << RED500 <<  this->_name << ":Zombie destructor called" << RESET << std::endl;
}

void Zombie::setName(std::string n_name) {
    this->_name = n_name;
}

std::string Zombie::getName(void) {
    return this->_name;
}

void Zombie::announce(void) {
    std::cout << CYAN500 << this->_name << ":BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
