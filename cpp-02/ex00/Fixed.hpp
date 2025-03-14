#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <string>

class Fixed {
    private:
        int _value;
        const static int _bits = 8;
    public:
        Fixed();
        Fixed(const Fixed& a);
        ~Fixed();
        Fixed& operator = (const Fixed& a);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};


#endif