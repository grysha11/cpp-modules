#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal {
    private:
        Brain* _brain;
    public:
        Dog();
        Dog(std::string ideas);
        Dog(const Dog& other);
        ~Dog();
        Dog& operator = (const Dog& other);
        void makeSound(void) const;
};

#endif