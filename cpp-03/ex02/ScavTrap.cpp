#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->_hp = 100;
    this->_energy = 50;
    this->_damage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_hp = 100;
    this->_energy = 50;
    this->_damage = 20;
    std::cout << "Modifed ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(ClapTrap& other) : ClapTrap(other) {
    this->_hp = 100;
    this->_energy = 50;
    this->_damage = 20;
    std::cout << " ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap default destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hp = other._hp;
        this->_energy = other._energy;
        this->_damage = other._damage;
    }
    std::cout << "Assignment ScavTrap operator called" << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string &target) {
    if (this->_hp <= 0) {
        std::cout << "ScavTrap " << this->_name << " is dead" << std::endl;
        return ;
    }
    if (this->_energy) {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
        this->_energy--;
    }
    std::cout << "ScavTrap " << this->_name << " don't have energy..." << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
    if (this->_hp <= 0) {
        std::cout << "ScavTrap " << this->_name << " is dead" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " took " << amount << " damage points" << std::endl;
    this->_hp -= amount;
    if (this->_hp <= 0) {
        std::cout << "ScavTrap " << this->_name << " died from powerfull atack :(" << std::endl;
    }
}

void ScavTrap::beRepaired(unsigned int amount) {
    std::cout << "ScavTrap " << this->_name << " repaired " << amount << " health points" << std::endl;
    this->_hp += amount;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}
