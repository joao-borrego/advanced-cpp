#ifndef COMPLEX_H_
#define COMPLEX_H_


#include <iostream>
using namespace std;

namespace CustomMath {

class Complex {

private:
    
    double real; 
    double imaginary;

public:
    
    Complex();

    Complex(double real, double imaginary);

    Complex(const Complex &other);

    Complex &operator=(const Complex &other);

    friend Complex operator+(const Complex &c1, const Complex &c2);
    friend Complex operator+(const Complex &c, const double d);
    friend Complex operator+(const double d, const Complex &c);

    const bool operator==(const Complex &other) const;
    const bool operator!=(const Complex &other) const;

    Complex operator*() const;

    friend ostream &operator<<(ostream &out, const Complex &c);
};

}

#endif
