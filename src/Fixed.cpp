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

double Fixed::toDouble(void) const {
    return (float)this->_raw / (float)(1 << Fixed::_frac_bits);
}

std::ostream& operator<<(std::ostream &output, const Fixed &obj) {
    output << obj.toDouble();

    return output;
}

bool Fixed::operator>(const Fixed &toBeCompared) const {
    return this->getRawBits() > toBeCompared.getRawBits();
}

bool Fixed::operator<(const Fixed &toBeCompared) const {
    return this->getRawBits() < toBeCompared.getRawBits();
}

bool Fixed::operator==(const Fixed &toBeCompared) {
    return this->getRawBits() == toBeCompared.getRawBits();
}

bool Fixed::operator>=(const Fixed &toBeCompared) {
    return (*this) > toBeCompared || (*this) == toBeCompared;
}

bool Fixed::operator<=(const Fixed &toBeCompared) {
    return (*this) < toBeCompared || (*this) == toBeCompared;
}

bool Fixed::operator!=(const Fixed &toBeCompared) {
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
    this->operator++();
    return old;
}

Fixed Fixed::operator--(int) {
    Fixed old(*this);
    this->operator--();
    return old;
}

Fixed &Fixed::operator++(void) {
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed &Fixed::operator--(void) {
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2) {
    if (n1 > n2) {
        return n2;
    }
    return n1;
}

const Fixed &Fixed::min(const Fixed &n1, const Fixed &n2) {
    return Fixed::min((Fixed &)n1, (Fixed &)n2);
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2) {
    if (n1 > n2) {
        return n1;
    }
    return n2;
}

const Fixed &Fixed::max(const Fixed &n1, const Fixed &n2) {
    return Fixed::max((Fixed &)n1, (Fixed &)n2);
}

Fixed Fixed::abs(void) const {
    Fixed result;

    int rawBits = this->getRawBits();
    if (rawBits < 0) {
        rawBits *= -1;
    }
    result.setRawBits(rawBits);
    return result;
}

Fixed::~Fixed(void) = default;
