#include <iostream>
#include <vector>

using namespace std;


class Test {
private:
    static const int SIZE = 100; 
    int _id {0};
    int *_pBuffer {nullptr};

    // Counter for instances of Test, for debugging
    static int &getCounter() {
        static int counter = 0;
        return counter;
    }

public:
    
    Test() {
        _id = getCounter()++;
        _pBuffer = new int[SIZE] {};
        cout << "Constructor " << *this << endl;
    }

    Test(int num) {
        _id = getCounter()++;
        _pBuffer = new int[SIZE] {};
        for (int i = 0; i < SIZE; i++) {
            _pBuffer[i] = i * num;
        }
        cout << "Parameterized constructor " << *this << endl;
    }

    Test(const Test &other) {
        _id = getCounter()++;
        cout << "Copy constructor " << *this << " from " << other << endl;
        _pBuffer = new int[SIZE] {};
        // Equivalent to memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
        std::copy(other._pBuffer, other._pBuffer + SIZE, _pBuffer);
    }

    Test(Test &&other) {
        _id = getCounter()++;
        cout << "Move constructor " << *this << " from " << other << endl;
        _pBuffer = other._pBuffer;
        other._pBuffer = nullptr;
    }

    // Creates a hard-copy from another instance
    Test &operator=(const Test &other) {
        cout << "Assignment " << *this << " := " << other << endl;
        if (this != &other) {
            delete [] _pBuffer;
            _pBuffer = new int[SIZE] {};
            std::copy(other._pBuffer, other._pBuffer + SIZE, _pBuffer);
        } else {
            cout << "Self-assignment: do nothing" << endl;    
        }
        return *this;
    }

    // Frees own resources and steals them from another instance
    Test &operator=(Test &&other) {
        cout << "Move assignment " << *this << " := " << other << endl;
        if (this != &other) {
            delete [] _pBuffer;
            _pBuffer = other._pBuffer;
            other._pBuffer = nullptr;
        } else {
            cout << "Self-assignment: do nothing" << endl;    
        }
        return *this;
    }

    ~Test() {
        cout << "Destructor " << *this << endl;
        delete [] _pBuffer;
    }

    friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test) {
    out << "Test(id=" << test._id << ")";
    return out;
}

// Helper functions to determine whether argument is lvalue or rvalue
// Making these into a template turns everything into rvalue...

void check(const int &lvalue) {
    cout << "Called with lvalue " << lvalue << endl;
}

void check(int &&rvalue) {
    cout << "Called with rvalue " << rvalue << endl;
}

void check(const Test &lvalue) {
    cout << "Called with lvalue " << lvalue << endl;
}

void check(Test &&rvalue) {
    cout << "Called with rvalue " << rvalue << endl;
}

Test getTest() {
    return Test();
}


int main() {

    Test test0;
    cout << test0 << endl;

    vector<Test> vec;
    // Move constructor, resources allocated once, then moved
    vec.push_back(Test());

    cout << endl;

    Test test3;
    test3 = test0;

    cout << endl;

    Test test4 = Test();
    // Move assignment
    test4 = getTest();
    // Self assignment does nothing
    test4 = test4;

    cout << endl;

    // rvalues and lvalues
    
    int foo = 7;
    int *pFoo = &foo;
    // Compile-time error: taking address of rvalue 
    // int *pFooInvalid = &7;

    Test *pTest = &test0;
    // Compile-time error: taking address of rvalue
    // Test *pTestInvalid = &Test();

    // Equivalent to &++foo, *pValue gets 8
    int *pValue = &(++foo);
    // Compile-time error: lvalue required as unary '&' operand
    // Temporary copy of foo after increment is an rvalue
    // int *pValue = &(foo++);

    Test &pTest1 = test0;
    // Extends lifetime of temporary variable returned from Test() ctor
    const Test &pTest2 = Test();

    Test &&rValRef1 = Test();

    cout << endl;

    // Check rvalue and lvalue 

    check(foo);
    check(foo++);
    check(++foo);

    cout << endl;

    check(test0);
    check(Test());

    cout << endl;

    return 0;
}
