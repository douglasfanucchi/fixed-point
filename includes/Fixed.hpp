#ifndef FIXED_H
# define FIXED_H

class Fixed
{
    private:
        int _raw;

    public:
        Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif