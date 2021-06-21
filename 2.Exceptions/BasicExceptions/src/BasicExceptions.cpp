#include <iostream>
using namespace std;


void canThrow() {

    // int
    // throw 8;
    
    // const char *
    // throw "Something went wrong";
    
    // string
    throw string("Something else went wrong");
}

int main() {
    try {
        canThrow();
    }
    catch(int exc) {
        cout << "Error code: " << exc << endl;
    }
    catch (const char* exc) {
        cout << "Error message: " << exc << endl;
    }
    catch (string &exc) {
        cout << "Error message: " << exc << endl;
    }


    return 0;
}
