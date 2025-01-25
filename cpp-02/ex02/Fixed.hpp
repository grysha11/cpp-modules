#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <string>
#include <cmath>

class Fixed {
    private:
        int _value;
        const static int _bits = 8;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        ~Fixed();
        Fixed& operator = (const Fixed& other);
        bool operator > (const Fixed& other) const;
        bool operator >= (const Fixed& other) const;
        bool operator < (const Fixed& other) const;
        bool operator <= (const Fixed& other) const;
        bool operator == (const Fixed& other) const;
        bool operator != (const Fixed& other) const;
        Fixed operator + (const Fixed& other);
        Fixed operator - (const Fixed& other);
        Fixed operator * (const Fixed& other);
        Fixed operator / (const Fixed& other);
        Fixed& operator ++ ();
        Fixed operator ++ (int);
        Fixed& operator -- ();
        Fixed operator -- (int);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt(void) const;
        float toFloat(void) const;
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& other);

#endif