#include <iostream>

using namespace std;


void test(void (*pFunc)()) {
    pFunc();
}

void testGreet(void (*greet)(const string &)) {
    greet("Bob");
}

class Test {
private:
    int one {1};
    int two {2};

public:
    void run() {
        int three {3};
        int four {4};

        auto pLambda = [this, three, four](){
            one = 10; // passed by reference
            cout << one << endl;
            cout << two << endl;
            cout << three << endl;
            cout << four << endl;
        };

        pLambda();
    }
};


int main() {

    auto pHello = [](){ cout << "Hello!" << endl; };
    pHello();

    test(pHello);
    test([](){ cout << "Hello again!" << endl; });

    auto pGreet = [](const string &name){ cout << "Hello " << name << endl; };

    pGreet("Mike");
    testGreet(pGreet);

    auto pDivide = [](double a, double b) -> double {
        if (b == 0.0) {
            // If we return 0.0 there's no ambiguity in the return type
            // Compiler deduces that both statements return a double
            return 0;
        }
        return a/b;
    };

    auto res = pDivide(10.0, 5.0);
    cout << res << endl << endl;

    // Lambda capture expressions

    int one = 1, two = 2, three = 3;

    // Capure one and two by value
    [one, two]() { cout << one << "," << two << endl; }();
    
    // Capture all local variables by value
    [=]() { cout << one << "," << two << "," << three << endl; }();
    
    // Capture all local variables by value, but three by reference
    [=, &three] {
        three = 12;
        cout << one << "," << two << "," << three << endl;
    }();
    cout << three << endl;
    
    // Capture all local variables by reference
    [&]() {
        one = 2;
        two = 4;
    }();
    cout << one << "," << two << "," << three << endl;

    // Capture all local variables by reference, but two and three by value
    [&, two, three]() {
        one = 100;
        cout << one << "," << two << "," << three << endl;        
    }();

    cout << endl;

    Test test;
    test.run();

    return 0;
}
