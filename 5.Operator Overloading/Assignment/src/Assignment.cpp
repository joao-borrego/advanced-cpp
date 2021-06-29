#include <iostream>
using namespace std;


class Test {

private:
    int id;
    string name;

public:
    Test(): id(0), name("") {

    }


    Test(int id, string name): id(id), name(name) {

    }

    Test(const Test &other) {
        cout << "Copy constructor called on " << flush;
        other.print();
        // Calls assignment operator
        *this = other;
    }

    void print() const {
        cout << "Test(id="<< id << ", name=" << name << ")" << endl;
    }

    Test &operator=(const Test &other) {
        cout << "Assignment called on " << flush;
        other.print();

        id = other.id;
        name = other.name;
    
        return *this;
    }
};

int main() {
    
    Test test1(10, "Mike");
    cout << "test1=" << flush;
    test1.print();


    Test test2(20, "Bob");
    test2 = test1;
    cout << "test2=" << flush;
    test2.print();

    Test test3;
    // Expanded syntax for assignment operation
    test3.operator=(test1);
    cout << "test3=" << flush;
    test3.print();

    cout << endl;

    // Not assignment, but copy initialization
    Test test4 = test1;
    cout << "test4=" << flush;
    test4.print();

    return 0;
}
