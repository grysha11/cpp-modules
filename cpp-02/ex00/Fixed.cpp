#include "Fixed.hpp"

Fixed::Fixed() {
    this->_value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    this->_value = other._value;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Default destructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed& other) {
    if (this != &other) {
        this->_value = other._value;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}
