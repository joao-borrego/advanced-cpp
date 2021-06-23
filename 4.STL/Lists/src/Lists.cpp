#include <iostream>
#include <list>

using namespace std;


void printList(list<int> &numbers) {
    for (const auto& elem : numbers) {
        cout << elem << " ";
    }
    cout << endl;
}


int main() {
    
    list<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);
    printList(numbers);

    // Insert 100 at the start
    auto it = numbers.begin();
    numbers.insert(it, 100);
    printList(numbers);

    // Remove element 0
    auto eraseIt = numbers.begin();
    eraseIt++;
    eraseIt = numbers.erase(eraseIt);
    printList(numbers);

    // Insert 200 before element 2
    for (auto it = numbers.begin(); it != numbers.end(); it++) {
        if (*it == 2)
            numbers.insert(it, 200);
    }
    printList(numbers);

    return 0;
}
