#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

class Animal {
    protected:
        std::string _type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& other);
        virtual ~Animal();
        Animal& operator = (const Animal& other);
        virtual void makeSound(void) const;
        const std::string& getType(void) const;
};

class WrongAnimal {
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& other);
        virtual ~WrongAnimal();
        WrongAnimal& operator = (const WrongAnimal& other);
        void makeSound(void) const;
        const std::string& getType(void) const;
};

#endif