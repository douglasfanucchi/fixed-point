#ifndef FIXED_H
# define FIXED_H

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
        int getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt(void);
        double toDouble(void);
};

#endif