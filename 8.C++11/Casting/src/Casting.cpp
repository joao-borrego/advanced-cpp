#include <iostream>

using namespace std;


class Parent {
public:
    virtual void speak() {
        cout << "Parent" << endl;
    }
};

class Brother: public Parent {
public:
    void speak() {
        cout << "Brother" << endl;
    }
};

class Sister: public Parent {
public:
    void speak() {
        cout << "Sister" << endl;
    }
};


int main() {

    Parent parent;
    Brother brother;

    // Static cast - compile-time

    Parent *pParent1 = &brother;
    // Compile-time error: invalid conversion (downcasting)
    //Brother *pBrother = &parent;
    // Compiles but in general it's unsafe
    Brother *pBrother1 = static_cast<Brother *>(&parent);
    // Is safe only because pParent1 points at a Brother instance
    Brother *pBrother2 = static_cast<Brother *>(pParent1);

    pBrother2->speak();

    Parent &&rValParent1 = Parent();
    // Compile-time error: cannot bind rvalue reference Parent&& to lvalue Parent
    // Parent &&p = parent;
    // Compiles and should be safe
    Parent rValParent2 = static_cast<Parent &&>(parent);

    rValParent1.speak();
    rValParent2.speak();

    // Dynamic cast - runtime

    Parent *pParent2 = &parent;
    // Runtime checking if the cast is valid
    Brother *pBrother3 = dynamic_cast<Brother *>(pParent1);
    if (pBrother3 != nullptr) {
        cout << "Valid cast from Brother* to Brother*" << endl;
    }
    Brother *pBrother4 = dynamic_cast<Brother *>(pParent2);
    if (pBrother4 == nullptr) {
        cout << "Invalid cast from Parent* to Brother*" << endl;
    }

    // Reinterpret cast

    Parent *pParent3 = &brother;
    Sister *pSister1 = dynamic_cast<Sister *>(pParent3);
    if (pBrother4 == nullptr) {
        cout << "Invalid cast from Brother* to Sister*" << endl;
    }
    // Compiles, but it's even more permissive than static_cast. Unsafe
    Sister *pSister2 = reinterpret_cast<Sister *>(pParent3);

    return 0;
}
