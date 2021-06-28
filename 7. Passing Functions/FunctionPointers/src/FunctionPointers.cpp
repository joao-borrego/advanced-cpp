#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void test() {
    cout << "Hello" << endl;
}

float anotherTest(int a, int b) {
    cout << "Hello " << a << " " << b << endl;
    return 2.5f;
}

bool SizeIs3(string test) {
    return test.size() == 3;
}

int countStrings(vector<string> vec, bool (*matchFcn)(string test) ) {

    int count = 0;
    for (const auto elem : vec) {
        if (matchFcn(elem)) {
            count++;
        }
    }
    return count;
}


int main() {

    //void (*pTest)();
    //pTest = &test;
    //(*pTest)();

    // Equivalent but more compact 
    void (*pTest)(void) = test;
    pTest();

    float (*pOtherTest)(int, int) = anotherTest;
    float rv = anotherTest(3, 4);
    cout << "anotherTest returned " << rv << endl;

    vector<string> vec = {"one", "two", "three", "two", "four", "two", "three"};
    int count = countStrings(vec, SizeIs3);
    cout << "countStrings returned " << count << endl;

    return 0;
}
