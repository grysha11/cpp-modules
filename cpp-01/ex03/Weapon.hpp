#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <string>

class Weapon {
    private:
        std::string type;
    public:
        Weapon(std::string init_type);
        ~Weapon();
        void setType(std::string n_type);
        const std::string& getType();
};

#endif