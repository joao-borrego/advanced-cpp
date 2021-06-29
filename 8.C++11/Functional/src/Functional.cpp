#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;


bool checkFunction(const string &test) {
    return test.size() == 3;
}

class Check {
public:
    bool operator()(const string &test) {
        return test.size() == 5;
    }
} checkFunctor;

void run(function<bool(const string &)> check) {
    cout << check("dog") << endl;
}


int main() {

    int size = 5;
    vector<string> vec {"one", "two", "three"};
    auto lambda = [size](const string &test) { return test.size() == size; };
    int count = count_if(vec.begin(), vec.end(), lambda);
    cout << count << endl;

    count = count_if(vec.begin(), vec.end(), checkFunction);
    cout << count << endl;

    count = count_if(vec.begin(), vec.end(), checkFunctor);
    cout << count << endl;

    run(lambda);
    run(checkFunction);
    run(checkFunctor);

    function<int(int, int)> add = [](int a, int b){ return a + b; };
    cout << add(7, 3) << endl;

    return 0;
}
