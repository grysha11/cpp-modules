#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hp(10), _energy(10), _damage(0) {
    std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _energy(10), _damage(0) {
    std::cout << "Modifed ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& other) : _name(other._name), _hp(10), _energy(10), _damage(0) {
    std::cout << "Copy constructor ClapTrap called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "Default ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hp = other._hp;
        this->_energy = other._energy;
        this->_damage = other._damage;
    }
    std::cout << "Assignment ClapTrap operator called" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string &target) {
    if (this->_hp <= 0) {
        std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
        return ;
    }
    if (this->_energy) {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
        this->_energy--;
    }
    std::cout << "ClapTrap " << this->_name << " don't have energy..." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hp <= 0) {
        std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " took " << amount << " damage points" << std::endl;
    this->_hp -= amount;
    if (this->_hp <= 0) {
        std::cout << "ClapTrap " << this->_name << " died from powerfull atack :(" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "ClapTrap " << this->_name << " repaired " << amount << " health points" << std::endl;
    this->_hp += amount;
}
