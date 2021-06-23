#include <iostream>
#include <map>
#include <utility>

using namespace std;


class Person {

private:
    string name;
    int age;

public:

    Person(): name(""), age(0) { }

    Person(string name, int age) :
        name(name), age(age) {
    }

    Person(const Person &other) : 
           name(other.name),
           age(other.age) {

        cout << "Copy constructor called for " << name << endl;
    }

    Person(Person &&other) :
           name(move(other.name)),
           age(exchange(other.age, 0)) {

        cout << "Move constructor called for " << name << endl;        
    }

    // Needed so the class can be used as a key in maps
    bool operator<(const Person &other) const {
        if (name == other.name)
            return age < other.age;
        return name < other.name;
    }

    void print() const {
        cout << name << ": " << age << endl;
    }           
};


int main() {
    

    map<Person, int> peopleAsKeys;
    peopleAsKeys.insert(make_pair(Person("Mike", 45), 40));
    peopleAsKeys.insert(make_pair(Person("Mike", 40), 40));
    peopleAsKeys.insert(make_pair(Person("Peter", 55), 55));

    for (auto it = peopleAsKeys.begin(); it != peopleAsKeys.end(); it++) {
        // Copy constructor called here, when the keyValue pair is created
        auto keyValue = *it;
        keyValue.first.print();
    }

    cout << endl;

    map<int, Person> peopleAsValues;
    peopleAsValues.insert(make_pair(40, Person("Mike", 40)));
    peopleAsValues.insert(make_pair(55, Person("Peter", 55)));
    // peopleAsValues[30] = Person("Mike", 40) is a compile-time error

    for (auto it = peopleAsValues.begin(); it != peopleAsValues.end(); it++) {
        // Copy constructor called here, when the keyValue pair is created
        auto keyValue = *it;
        keyValue.second.print();
    }

    return 0;
}
