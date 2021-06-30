#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;


class Test {
private:
    int _d {5};

public: 
    int add(int a, int b, int c) {
        cout << a << ", " << b << ", " << c << ", " << _d << endl;
        return a + b + c + _d;
    }
};


int add(int a, int b, int c) {
    cout << a << ", " << b << ", " << c << endl;
    return a + b + c;
}

void run(function<int(int, int)> func) {
    cout << func(7, 3) << endl;;
}


int main() {

    auto calculate1 = bind(add, 3, 4, 5);
    cout << calculate1() << endl;

    auto calculate2 = bind(add, _1, _2, _3);
    cout << calculate2(10, 20, 30) << endl;

    auto calculate3 = bind(add, _3, _1, _2);
    cout << calculate3(10, 20, 30) << endl;

    auto calculate4 = bind(add, _1, 20, _2);
    cout << calculate4(10, 30) << endl;
    run(calculate4);

    Test test;
    auto calculate5 = bind(&Test::add, test, _1, 20, _2);
    cout << calculate5(10, 30) << endl;

    return 0;
}
