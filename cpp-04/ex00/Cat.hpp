#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat();
        Cat(std::string name);
        Cat(const Cat& other);
        ~Cat();
        Cat& operator = (const Cat& other);
        void makeSound(void) const;
};

#endif