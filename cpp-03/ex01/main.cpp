#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Friend1");
    a.attack("ENEMY!!!");
    a.takeDamage(10);
    a.beRepaired(2);

    return 0;
}