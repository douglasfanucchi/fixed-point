#ifndef FIXED_H
# define FIXED_H

#include <ostream>

class Fixed
{
    private:
        int _raw;

    public:
        static int const _frac_bits = 8;
        Fixed();
        Fixed(Fixed const &fixed);
        Fixed(int number);
        Fixed(double number);
        ~Fixed(void);
        Fixed &operator=(Fixed &fixed);
        bool operator>(Fixed &toBeCompared);
        bool operator<(Fixed &toBeCompared);
        bool operator==(Fixed &toBeCompared);
        bool operator>=(Fixed &toBeCompared);
        bool operator <=(Fixed &toBeCompared);
        bool operator !=(Fixed &toBeCompared);
        Fixed operator+(const Fixed &n);
        Fixed operator-(const Fixed &n);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt(void);
        double toDouble(void);
};

std::ostream &operator<<(std::ostream &str, Fixed &obj);

#endif