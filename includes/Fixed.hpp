#ifndef FIXED_H
# define FIXED_H

#include <ostream>

class Fixed
{
    private:
        int _raw;

    public:
        static int const _frac_bits = 8;
        static Fixed &min(Fixed &n1, Fixed &n2);
        static const Fixed &min(const Fixed &n1, const Fixed &n2);
        static Fixed &max(Fixed &n1, Fixed &n2);
        static const Fixed &max(const Fixed &n1, const Fixed &n2);
        Fixed();
        Fixed(Fixed const &fixed);
        Fixed(int number);
        Fixed(double number);
        ~Fixed(void);
        Fixed &operator=(Fixed &fixed);
        bool operator>(const Fixed &toBeCompared) const;
        bool operator<(const Fixed &toBeCompared) const;
        bool operator==(const Fixed &toBeCompared);
        bool operator>=(const Fixed &toBeCompared);
        bool operator <=(const Fixed &toBeCompared);
        bool operator !=(const Fixed &toBeCompared);
        Fixed operator+(const Fixed &n);
        Fixed operator-(const Fixed &n);
        Fixed operator*(const Fixed &n);
        Fixed operator/(const Fixed &n);
        Fixed operator++(int);
        Fixed operator--(int);
        Fixed &operator++(void);
        Fixed &operator--(void);
        Fixed abs(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt(void);
        double toDouble(void) const;
};

std::ostream &operator<<(std::ostream &str, const Fixed &obj);

#endif