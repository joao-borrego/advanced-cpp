#include <iostream>

using namespace std;


class Test {

};

// The type T can be inferred as either lvalue or rvalue
template<typename T>
void call(T &&arg) {
    // forward<T> here is equivalent to static_cast<T>
    check(forward<T>(arg));
    // check(arg); This would always return lvalue
}

void check(Test &test) {
    cout << "lvalue" << endl;
}

void check(Test &&test) {
    cout << "rvalue" << endl;
}


int main() {

    Test test;
    // rvalue
    call(Test());
    // lvalue
    call(test);

    return 0;
}
