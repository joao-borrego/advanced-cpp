#include <iostream>
#include "Templates.h"

using namespace std;

int main() {
    
    Printer<int> intPrinter(5);
    intPrinter.print();

    Printer<string> strPrinter("Hello World!");
    strPrinter.print();

    print("HelloWorld");
    print(10);

    return 0;
}
