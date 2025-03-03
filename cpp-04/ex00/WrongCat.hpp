#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(std::string name);
        WrongCat(const WrongCat& other);
        ~WrongCat();
        WrongCat& operator = (const WrongCat& other);
        void makeSound(void) const;
};

#endif