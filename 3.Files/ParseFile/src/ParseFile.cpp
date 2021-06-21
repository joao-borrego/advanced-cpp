#include <iostream>
#include <fstream>

using namespace std;


// Usage: ./ParseFile /path/to/stats/file
// e.g. `./ParseFile ../../data.txt`
int main(int argc, const char* argv[]) {
    
    ifstream inFile;
    const auto inputFilePath = argv[1];

    inFile.open(inputFilePath);
    if (!inFile.is_open()) {
        cout << "Could not open file: " << inputFilePath << endl;
        return 1;
    }

    while(inFile) {
        string line;
        int population;
        
        // read line until `:` separator
        getline(inFile, line, ':');
        inFile >> population;

        // discards new line character
        // inFile.get();
        inFile >> ws; // read whitespace

        if (!inFile)
            break;

        cout << line << " -- " << population << endl;
    }


    inFile.close();

    return 0;
}
