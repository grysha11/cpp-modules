#include "Weapon.hpp"

Weapon::Weapon(std::string init_type) {
    this->type = init_type;
    std::cout << "Weapon constructor called" << std::endl;
}

Weapon::~Weapon() {
    
}

const std::string& Weapon::getType() {
    return this->type;
}


void Weapon::setType(std::string n_type) {
    this->type = n_type;
}
