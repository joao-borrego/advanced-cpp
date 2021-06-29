#include <iostream>
#include <vector>

using namespace std;


// Abstract class with only pure virtual methods
class Animal {
public:
    // Pure virtual functions
    virtual void run() = 0;
    virtual void speak() = 0;
};

// Abstract class since it does not implement run()
class Dog : public Animal {
public:
    // Specifying virtual here is not necessary
    virtual void speak() {
        cout << "Woof!" << endl;
    }
};

class Labrador : public Dog {
public:    
    virtual void run() {
        cout << "Labrador is running" << endl;
    }
};

class ShibaInu : public Dog {
public:    
    virtual void run() {
        cout << "Shiba Inu is running" << endl;
    }
};

void speak(Animal &a) {
    a.speak();
}


int main() {
    

    // Compile-time error
    // Animal animal;
    
    // Compile-time error
    // Dog dog;

    Labrador lab;
    lab.speak();

    ShibaInu shiba;

    vector<Animal*> animals;
    animals.push_back(&lab);
    animals.push_back(&shiba);
    for (const auto animal : animals) {
        animal->run();
    }

    for (const auto animal : animals) {
        speak(*animal);
    }

    return 0;
}
