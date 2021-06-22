#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;


int main() {
    
    int initialSize = 5;
    vector<string> vect1(initialSize);
    assert (vect1.size() == 5);

    vect1.push_back("one");
    vect1.push_back("two");
    vect1.push_back("three");

    assert (vect1.size() == 8);

    vector<string> vect2(initialSize, "default");
    vector<string> vect3 {"one", "two", "three"};
    
    // Initialize from array
    string array[] = {"one", "two", "three"};
    int arraySize = sizeof(array) / sizeof(array[0]); 
    vector<string> vect4(array, array + arraySize);

    // Initialize from another vector
    vector<string> vect5(vect4.begin(), vect4.end());

    // Various ways to iterate over elements 

    for (int i = 0; i < vect2.size(); i++) {
        cout << vect2[i] << " ";
    }
    cout << endl;

    for (vector<string>::iterator it = vect3.begin(); it != vect3.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // For read-only access of each element
    for (const auto& elem : vect4) {
        cout << elem << " ";
    }
    cout << endl;

    // With std::for_each and lambda inline function
    auto printLambda = [](const string& elem) { std::cout << elem << " "; };
    // cbegin() returns a constant iterator
    for_each(vect5.cbegin(), vect5.cend(), printLambda);
    cout << endl;

    // Vector capcity is increased
    vector<double> numbers(0);
    int capacity = numbers.capacity();
    for (int i = 0; i < 10000; i++) {
        if (numbers.capacity() != capacity) {
            cout << "capacity=" << capacity << endl;
            capacity = numbers.capacity();
        }
        numbers.push_back(i);
    }

    return 0;
}
