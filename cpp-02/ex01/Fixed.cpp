#include "Fixed.hpp"

Fixed::Fixed() {
    this->_value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    this->_value = value;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) {
    this->_value = static_cast<float>(value);
    std::cout << "Float constructor called" << std::endl;
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

int Fixed::toInt(void) {
    return this->_value >> this->_bits;
}

float Fixed::toFloat(void) {
    return static_cast<float>(this->_value) / (1 << this->_bits);
}
