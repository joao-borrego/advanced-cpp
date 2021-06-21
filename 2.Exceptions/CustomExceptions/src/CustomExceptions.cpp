#include <iostream>
#include <exception>

using namespace std;


class MyException: public exception {
public:
    // Note: throw() statement with no arguments informs the compiler that this
    // method should not throw an exception.
    // Dynamic exception specifications are deprecated in C++11
    virtual const char* what() const throw() {
        return "Something bad happened";
    }
};


class Test {
public:
    // Adding a throw() statement will result in a runtime failure
    // void canThrow throw() {
    void canThrow() {
        throw MyException();
    }
};

int main() {

    Test test;

    try {
        test.canThrow();
    }
    catch(MyException &exc) {
        cout << "Caught exception: " << exc.what() << endl;
    }

    return 0;
}
