#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << GREEN500 << this->name << ":Zombie constructor called" << RESET << std::endl;
}

Zombie::~Zombie() {
    std::cout << RED500 <<  this->name << ":Zombie destructor called" << RESET << std::endl;
}

void Zombie::setName(std::string n_name) {
    this->name = n_name;
}

std::string Zombie::getName(void) {
    return this->name;
}

void Zombie::announce(void) {
    std::cout << CYAN500 << this->name << ":BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
