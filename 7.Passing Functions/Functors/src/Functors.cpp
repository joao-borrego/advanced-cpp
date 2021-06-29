#include <iostream>

using namespace std;


struct Test {
    virtual bool operator()(const string &test) = 0;
};

// Functor
struct IsLion : public Test {
    virtual bool operator()(const string &text) {
        return text == "lion";
    }
};

struct IsCat : public Test {
    virtual bool operator()(const string &text) {
        return text == "cat";
    }
};

void check(string &text, Test &predicate) {
    cout << "predicate(" << text << ")=" << predicate(text) << endl;
}


int main() {

    IsLion predIsLion;
    IsCat predIsCat;
    string s1 = "lion";
    string s2 = "cat";

    cout << "predicate IsLion" << endl;
    check(s1, predIsLion);
    check(s2, predIsLion);

    cout << endl;

    cout << "predicate IsCat" << endl;
    check(s1, predIsCat);
    check(s2, predIsCat);

    return 0;
}
