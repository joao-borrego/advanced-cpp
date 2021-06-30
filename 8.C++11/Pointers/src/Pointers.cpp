#include <iostream>
#include <memory>

using namespace std;


class Test {
public:
    Test () {
        cout << "Constructor" << endl;
    }

    void greet() {
        cout << "Hello" << endl;
    }

    ~Test (){
        cout << "Destructor" << endl;
    }
};

class Temp {
private:
    unique_ptr<Test[]> pTest;
public:
    Temp(): pTest(new Test[2]) {}
};


int main() {

    unique_ptr<Test> pTest1(new Test);
    pTest1->greet();
    // Compile-time error: deleted function; does not implement assignment
    // unique_ptr<Test> pTest2 = pTest1;

    Temp temp;

    shared_ptr<Test> pTest2 {nullptr};
    {
        shared_ptr<Test> pTest3 = make_shared<Test>();
        pTest2 = pTest3;
        // Resources of pTest3 are not freed just yet
    }

    cout << "Finished" << endl;

    return 0;

    // All resources are freed after the return
}
