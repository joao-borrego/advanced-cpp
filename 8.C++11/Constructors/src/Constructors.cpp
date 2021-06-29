#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


class Test {
private:
    static const int SIZE = 100; 
    int *_pBuffer;

public:
    Test() {
        cout << "Constructor" << endl;
        _pBuffer = new int[SIZE] {};
    }

    Test(int num) {
        cout << "Parameterized constructor" << endl;
        _pBuffer = new int[SIZE] {};
        for (int i = 0; i < SIZE; i++) {
            _pBuffer[i] = i * num;
        }
    }

    Test(const Test &other) {
        cout << "Copy constructor" << endl;
        _pBuffer = new int[SIZE] {};
        memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
    }

    // This implementation prevents memory leak since object is already constructed.
    Test &operator=(const Test &other) {
        cout << "Assignment" << endl;
        // Call copy constructor
        Test tmp(other);
        // Swap data member with tmp
        swap(*this, tmp);
        return *this;
        // Call tmp destructor
    }

    ~Test() {
        cout << "Destructor" << endl;
        delete [] _pBuffer;
    }

    friend void swap(Test &lhs, Test &rhs);

    friend ostream &operator<<(ostream &out, const Test &test);
};

void swap(Test &lhs, Test &rhs) {
    cout << "Swap" << endl;
    std::swap(lhs._pBuffer, rhs._pBuffer);
}

ostream &operator<<(ostream &out, const Test &test) {
    out << "Hello from test";
    return out;
}


int main() {

    Test test1;
    cout << test1 << endl;

    vector<Test> vec;
    vec.push_back(Test());

    Test test2;
    test2 = test1;

    return 0;
}
