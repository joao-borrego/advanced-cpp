#include <iostream>

using namespace std;

template <class T, class S>
auto add(T value1, S value2) -> decltype(value1 + value2) {
    return value1 + value2;
};

int retInt() {
    return 42;
}

auto ret() -> decltype(retInt()) {
    return retInt();
}

int main() {

    cout << add(1, add(4.1d, 5.0f)) << endl;
    cout << ret() << endl;

    return 0;
}
