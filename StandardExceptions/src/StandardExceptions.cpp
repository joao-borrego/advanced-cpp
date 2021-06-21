#include <iostream>
using namespace std;


class CanThrow {
public:
    CanThrow() {
        char *memory = new char[100000000000];
        delete [] memory;
    }

};

int main() {

    try {
        CanThrow instance;
    }
    catch(bad_alloc &exc) {
        cout << "Caught exception: " << exc.what() << endl;
    }

    return 0;
}
