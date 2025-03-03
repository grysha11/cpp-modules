#ifndef BRAIN_HPP
#define BRAIN_HPP
#include "Animal.hpp"

class Brain {
    private:
        std::string _ideas[100];
    public:
        Brain();
        Brain(std::string idea);
        Brain(const Brain& other);
        ~Brain();
        Brain& operator = (const Brain& other);
        void setIdeas(std::string idea);
        std::string getIdea(int i) const;
};

#endif