#include "Fixed.hpp"

Fixed::Fixed() {
    this->_value = 0;
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    this->_value = value * (1 << _bits);
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) {
    this->_value = roundf(value * (1 << _bits));
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    this->_value = other._value;
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
    // std::cout << "Default destructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed& other) {
    if (this != &other) {
        this->_value = other._value;
    }
    // std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

bool Fixed::operator > (const Fixed& other) const {
    return this->_value > other._value;
}

bool Fixed::operator >= (const Fixed& other) const {
    return this->_value >= other._value;
}

bool Fixed::operator < (const Fixed& other) const {
    return this->_value < other._value;
}

bool Fixed::operator <= (const Fixed& other) const {
    return this->_value <= other._value;
}

bool Fixed::operator == (const Fixed& other) const {
    return this->_value == other._value;
}

bool Fixed::operator != (const Fixed& other) const {
    return this->_value != other._value;
}

Fixed Fixed::operator + (const Fixed& other) {
    Fixed tmp(0);
    tmp._value = this->_value + other._value;
    return tmp;
}

Fixed Fixed::operator - (const Fixed& other) {
    Fixed tmp(0);
    tmp._value = this->_value - other._value;
    return tmp;
}

Fixed Fixed::operator * (const Fixed& other) {
    Fixed tmp(0);
    tmp._value = (this->_value * other._value) / (1 << _bits);
    return tmp;
}

Fixed Fixed::operator / (const Fixed& other) {
    Fixed tmp(0);
    tmp._value = (this->_value * (1 << _bits)) / other._value;
    return tmp;
}

Fixed& Fixed::operator ++ () {
    this->_value++;
    return *this;
}

Fixed Fixed::operator ++ (int) {
    Fixed tmp(*this);
    this->_value++;
    return tmp;
}

Fixed& Fixed::operator -- () {
    this->_value--;
    return *this;
}

Fixed Fixed::operator -- (int) {
    Fixed tmp(*this);
    this->_value--;
    return tmp;
}

int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

int Fixed::toInt(void) const{
    return (this->_value) / (1 << this->_bits);
}

float Fixed::toFloat(void) const{
    return static_cast<float>(this->_value) / (1 << this->_bits);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

std::ostream& operator<<(std::ostream& os, const Fixed& other) {
    os << other.toFloat();
    return os;
}
