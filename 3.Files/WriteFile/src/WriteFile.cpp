#include <iostream>
#include <fstream>

using namespace std;


int main() {
    
    //ofstream outFile;
    fstream outFile;
    ifstream inFile;


    const auto textFileName = "text.txt";
    //outFile.open(textFileName);
    outFile.open(textFileName, ios::out);

    if (!outFile.is_open()) {
        cout << "Could not create file: " << textFileName << endl;
        return 1;
    }

    outFile << "Hello there" << endl;
    outFile << 123 << endl;

    outFile.close();

    inFile.open(textFileName);
    if (!inFile.is_open()) {
        cout << "Could not open file: " << textFileName << endl;
        return 1;
    }

    string line;
    
    // equivalent to while(inFile.eof())
    while (inFile) {
        getline(inFile, line);
        cout << line << endl;
    }

    inFile.close();

    return 0;
}
