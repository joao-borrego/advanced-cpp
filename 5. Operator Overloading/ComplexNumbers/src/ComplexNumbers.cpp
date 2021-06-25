#include <iostream>
#include "Complex.h"

using namespace std;
using namespace CustomMath;


int main() {
    
    Complex c1(2,3);
    Complex c2(c1);

    cout << "c1=" << c1 << endl;
    cout << "c2=" << c2 << endl;

    Complex c3 = c1 + c2;

    cout << "c3=" << c3 << endl;
    cout << "(c1==c2)=" << (c1 == c2) << endl;
    cout << "(c1!=c2)=" << (c1 != c2) << endl;
    cout << "(c1==c3)=" << (c1 == c3) << endl;

    Complex c4 = 2.5 + c3 + 2.5;
    cout << "c4=" << c4 << endl;

    Complex c5 = *c4;
    cout << "c5=" << c5 << endl;

    return 0;
}
