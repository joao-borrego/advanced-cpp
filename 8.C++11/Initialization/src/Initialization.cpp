#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;


class Foo {
public:
    Foo(initializer_list<string> strings) {
        for (const auto s : strings) {
            cout << s << endl;
        }
    }
};

class Bar {
    int id {3};
    string name {"Mike"};

public:

    Bar() = default;

    Bar(const Bar &other) = default;

    Bar &operator=(const Bar &other) = delete;

    Bar(int id) : id(id) { }

    void print() const {
        cout << id << ": " << name << endl;
    }
};



int main() {

    // C++ 98

    class C {
    public:
        int id;
        string text;
    };

    C c98 = {1, "Hello"};

    struct S {
        int id;
        string text;
    };

    S s98 = {2, "Hi"};

    struct R {
        int id;
        string text;
    } r98_1 = {3, "Foo"}, r98_2 = {4, "Bar"};
    
    // C++ 11

    int value {5};
    
    string text {"Hello"};
    
    int numbers[] {1, 2, 3};
    
    int *pNumbers = new int[] {1, 2, 3};

    int *pInt; // equivalent to *pInt {nullptr}

    struct {
        int id;
        string text;
    } s11 {5, "Hi"};

    vector<string> v11 {"one", "two", "three"};

    // Custom classes

    Foo fruit {"apple", "orange", "banana"};

    Bar test1;
    test1.print();

    Bar test2(77);
    test2.print();

    Bar test3 = test1;
    // Throws compile-time error because we delete the assignment operator
    // test2 = test3;

    return 0;
}
