#include <Fixed.hpp>
#include <iostream>
#include <cmath>

Fixed::Fixed(void) {
    _raw = 0;
}

Fixed::Fixed(Fixed const &fixed) {
    _raw = fixed._raw;
}

Fixed::Fixed(int number) {
    this->setRawBits(number << Fixed::_frac_bits);
}

Fixed::Fixed(double number) {
    this->setRawBits(roundf(number * (1 << Fixed::_frac_bits)));
}

int Fixed::getRawBits(void) const {
    return _raw;
}

void Fixed::setRawBits(int const raw) {
    _raw = raw;
}

Fixed &Fixed::operator=(Fixed &fixed) {
    this->setRawBits(fixed.getRawBits());

    return *this;
}

int Fixed::toInt(void) {
    return this->_raw >> Fixed::_frac_bits;
}

double Fixed::toDouble(void) {
    return (float)this->_raw / (float)(1 << Fixed::_frac_bits);
}

std::ostream& operator<<(std::ostream &output, Fixed &obj) {
    output << obj.toDouble();

    return output;
}

bool Fixed::operator>(Fixed &toBeCompared) {
    return this->getRawBits() > toBeCompared.getRawBits();
}

bool Fixed::operator<(Fixed &toBeCompared) {
    return this->getRawBits() < toBeCompared.getRawBits();
}

bool Fixed::operator==(Fixed &toBeCompared) {
    return this->getRawBits() == toBeCompared.getRawBits();
}

bool Fixed::operator>=(Fixed &toBeCompared) {
    return (*this) > toBeCompared || (*this) == toBeCompared;
}

bool Fixed::operator<=(Fixed &toBeCompared) {
    return (*this) < toBeCompared || (*this) == toBeCompared;
}

bool Fixed::operator!=(Fixed &toBeCompared) {
    return !((*this) == toBeCompared);
}

Fixed Fixed::operator+(const Fixed &n) {
    Fixed result;

    result.setRawBits(this->getRawBits() + n.getRawBits());

    return result;
}

Fixed Fixed::operator-(const Fixed &n) {
    Fixed result;

    result.setRawBits(this->getRawBits() - n.getRawBits());

    return result;
}

Fixed Fixed::operator*(const Fixed &n) {
    Fixed result;

    result.setRawBits((this->getRawBits() * n.getRawBits()) >> Fixed::_frac_bits);

    return result;
}

Fixed Fixed::operator/(const Fixed &n) {
    Fixed result;

    result.setRawBits((signed long long)(this->getRawBits() << Fixed::_frac_bits) / n.getRawBits());

    return result;
}

Fixed Fixed::operator++(int) {
    Fixed old(*this);
    this->setRawBits(this->getRawBits() + 1);
    return old;
}

Fixed Fixed::operator--(int) {
    Fixed old(*this);
    this->setRawBits(this->getRawBits() - 1);
    return old;
}

Fixed::~Fixed(void) = default;
