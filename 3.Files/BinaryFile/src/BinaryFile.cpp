#include <iostream>
#include <fstream>

using namespace std;


// Align data on single byte boundaries
#pragma pack(push, 1)

struct Person {
    char name[50];
    int age;
    double height;
};

#pragma pack(pop)

// Usage: ./BinaryFile /path/to/file.bin
// e.g. `./BinaryFile ../../people.bin`
int main(int argc, const char* argv[]) {
    
    // Write to binary file

    Person person = {"Bob", 20, 1.7};

    fstream binFile;
    const auto binFileName = argv[1];
    
    binFile.open(binFileName, ios::binary | ios::out);
    if (!binFile.is_open()) {
        cout << "Could not open file: " << binFileName << endl;
        return 1;
    }

    // binFile.write((char *)&person, sizeof(Person));
    binFile.write(reinterpret_cast<char *>(&person), sizeof(Person));

    binFile.close();

    // Read from binary file

    Person otherPerson = {};

    binFile.open(binFileName, ios::binary | ios::in);
    if (!binFile.is_open()) {
        cout << "Could not open file: " << binFileName << endl;
        return 1;
    }

    binFile.read(reinterpret_cast<char *>(&otherPerson), sizeof(Person));
    cout << otherPerson.name << "; "
         << otherPerson.age << "; "
         << otherPerson.height << endl;

    return 0;
}
