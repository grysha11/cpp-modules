#include "MutantStack.hpp"

template<typename T, class Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {

}

template<typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {

}

template<typename T, class Container>
MutantStack<T, Container>::~MutantStack() {

}

template<typename T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator = (const MutantStack& other) {
    std::stack<T, Container>::operator = (other);
    return *this;
}

template<typename T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin() {
    return this->c.begin();
}

template<typename T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::end() {
    return this->c.end();
}
