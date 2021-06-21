#include <iostream>
#include <exception>

using namespace std;


void canThrow() {

    //throw bad_alloc();
    throw exception();
}

int main() {
    // Compiler produces warning if catch statement is written in the wrong order
    //  warning: exception of type ‘std::bad_alloc’ will be caught by earlier handler
    try {
        canThrow();
    }
    catch(bad_alloc &e) {
        cout << "bad_alloc specific exception: " << e.what() << endl;
    }
    catch (exception &e) {
        cout << "Generic exception: " << e.what() << endl;
    }

    return 0;
}
