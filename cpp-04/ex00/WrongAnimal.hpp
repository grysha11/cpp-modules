#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include "Animal.hpp"

class WrongAnimal {
    protected:
        std::string _type;
        std::string _name;
    public:
        WrongAnimal();
        WrongAnimal(std::string name);
        WrongAnimal(const WrongAnimal& other);
        virtual ~WrongAnimal();
        WrongAnimal& operator = (const WrongAnimal& other);
        void makeSound(void) const;
        const std::string& getType(void) const;
        const std::string& getName(void) const;
        void setName(std::string name);
};

#endif