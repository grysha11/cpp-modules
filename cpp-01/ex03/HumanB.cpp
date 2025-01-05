#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->_name = name;
    std::cout << "HumanB constructor called" << std::endl;
}

HumanB::~HumanB() {

}

void HumanB::setWeapon(Weapon& n_weapon) {
    this->_weapon = &n_weapon;
}

void HumanB::attack() {
    if (!this->_weapon) {
        std::cout << this->_name << "attacks with their fists" << std::endl;
    } else {
        std::cout << this->_name << "attacks with their " << this->_weapon->getType() << std::endl;
    }
}