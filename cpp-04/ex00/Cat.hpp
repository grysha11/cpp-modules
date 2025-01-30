#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat();
        Cat(std::string type);
        Cat(const Cat& other);
        ~Cat();
        Cat& operator = (const Cat& other);
        void makeSound(void) const;
};

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(std::string type);
        WrongCat(const WrongCat& other);
        ~WrongCat();
        WrongCat& operator = (const WrongCat& other);
        void makeSound(void) const;
};

#endif