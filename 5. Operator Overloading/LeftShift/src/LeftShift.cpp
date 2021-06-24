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
        cout << "Copy constructor called on " << other << endl;
        // Calls assignment operator
        *this = other;
    }

    Test &operator=(const Test &other) {
        cout << "Assignment called on " << other << endl;

        id = other.id;
        name = other.name;
    
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Test &test) {
        out << "Test(id=" << test.id << ", name=" << test.name << ")";
        return out;
    }
};

int main() {
    
    Test test1(10, "Mike");
    cout << "test1=" << test1 << flush;

    Test test2(20, "Bob");
    test2 = test1;
    cout << "test2=" << test2 << flush;

    Test test3;
    // Expanded syntax for assignment operation
    test3.operator=(test1);

    // Not assignment, but copy initialization
    Test test4 = test1;
    cout << "test3=" << test3 << " test4=" << test4 << endl;

    return 0;
}
