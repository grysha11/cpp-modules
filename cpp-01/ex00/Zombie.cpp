#include "Zombie.hpp"

Zombie::Zombie(std::string init_name) {
    name = init_name;
    std::cout << GREEN500 << "Zombie constructor called" << std::endl;
}

Zombie::~Zombie() {
    std::cout << RED500 << "Zombie destructor called" << std::endl;
}

void Zombie::setName(std::string n_name) {
    name = n_name;
}

std::string Zombie::getName(void) {
    return name;
}

void Zombie::announce(void) {
    std::cout << CYAN500 << name << ":BraiiiiiiinnnzzzZ..." << std::endl;
}
