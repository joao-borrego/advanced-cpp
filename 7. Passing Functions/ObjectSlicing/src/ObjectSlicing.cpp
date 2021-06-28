#include <iostream>

using namespace std;


class Parent {

private:
    int one;

public:

    Parent(): one(0) { }

    Parent(const Parent &other) {
        one = other.one;
        cout << "Copy ctor called Parent()" << endl;
    }

    void nonVirtualPrint() {
        cout << "Parent" << endl;
    }

    virtual void print() {
        cout << "Parent" << endl;
    }
};

class Child : public Parent {

private:
    int two;

public:

    Child(): two(0) {}

    void nonVirtualPrint() {
        cout << "Child" << endl;
    }

    void print() {
        cout << "Child" << endl;
    }
};


int main() {
    
    Child c1;
    Parent &p1 = c1;
    // Prints Parent
    p1.nonVirtualPrint();
    // Prints Child
    p1.print();

    // Copy constructor slices child
    Parent p2 = Child();
    // Prints Parent
    p2.print();

    return 0;
}
