#include "Complex.h"

using namespace std;


namespace CustomMath {


Complex::Complex(): real(0), imaginary(0) {}

Complex::Complex(double real, double imaginary)
    : real(real), imaginary(imaginary) {}

Complex::Complex(const Complex &other) {
    real = other.real;
    imaginary = other.imaginary;
}

Complex &Complex::operator=(const Complex &other) {
    real = other.real;
    imaginary = other.imaginary;
    return *this;
}

Complex operator+(const Complex &c1, const Complex &c2) {
    return Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

Complex operator+(const Complex &c, const double d) {
    return Complex(c.real + d, c.imaginary);
}

Complex operator+(const double d, const Complex &c) {
    return Complex(c.real + d, c.imaginary);
}


const bool Complex::operator==(const Complex &other) const {
    return (real == other.real && imaginary == other.imaginary);
}

const bool Complex::operator!=(const Complex &other) const {
    return !(*this == other);
}

Complex Complex::operator*() const {
    return Complex(real, -imaginary);
}

ostream &operator<<(ostream &out, const Complex &c) {
    out << "Complex(real=" << c.real << ", imaginary=" << c.imaginary << ")";
    return out;
}

}