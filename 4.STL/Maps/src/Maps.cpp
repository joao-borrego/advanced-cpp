#include <iostream>
#include <map>

using namespace std;



int main() {
    
    map<string, int> peopleAges;
    peopleAges["Mike"] = 40;
    peopleAges["Raj"] = 20;
    peopleAges["Vicky"] = 30;

    pair<string, int> peter("Peter", 100);
    peopleAges.insert(peter);

    peopleAges.insert(make_pair("Sarah", 50));

    if (peopleAges.find("Raj") != peopleAges.end()) {
        cout << peopleAges["Raj"] << endl;
    }

    if (peopleAges.find("Foo") == peopleAges.end()) {
        cout << "Foo key not found" << endl;
    }

    for (map<string, int>::iterator it = peopleAges.begin(); it != peopleAges.end(); it++) {
        pair<string, int> keyValue = *it;
        cout << keyValue.first << ": " << keyValue.second << endl;
        //cout << it->first << ": " << it->second << endl;
    }

    return 0;
}
