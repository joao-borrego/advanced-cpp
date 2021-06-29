#include <iostream>
#include "ring.h"

using namespace std;

int main() {

    ring<string> buffer(3);
    buffer.add("one");
    buffer.add("two");
    buffer.add("three");
    buffer.add("four");

    for (int i = 0; i < buffer.size(); i++) {
        cout << buffer.get(i) << endl;
    }
    cout << endl;

    // C++ 98 style
    for (ring<string>::iterator it = buffer.begin(); it != buffer.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;

    // C++ 11 style
    for (const auto elem : buffer) {
        cout << elem << endl;
    }

    return 0;
}
