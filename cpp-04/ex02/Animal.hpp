#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal {
    protected:
        std::string _type;
        std::string _name;
    public:
        Animal();
        Animal(std::string name);
        Animal(const Animal& other);
        virtual ~Animal();
        Animal& operator = (const Animal& other);
        virtual void makeSound(void) const = 0;
        const std::string& getType(void) const;
        const std::string& getName(void) const;
        void setName(std::string name);
};

#endif