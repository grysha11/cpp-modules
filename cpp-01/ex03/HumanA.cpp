#include "HumanA.hpp"

HumanA::~HumanA() {

}

void HumanA::attack() {
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}