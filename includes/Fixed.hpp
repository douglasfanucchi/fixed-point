#ifndef FIXED_H
# define FIXED_H

class Fixed
{
    private:
        int _raw;

    public:
        Fixed();
        Fixed(Fixed const &fixed);
        ~Fixed(void);
        Fixed &operator=(Fixed &fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif