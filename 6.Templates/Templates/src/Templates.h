#include <iostream>

using namespace std;


template<class T>
class Printer {

private:
	T obj;

public:
	Printer(T obj) : obj(obj) { }

	void print() {
		cout << obj << endl;
	}
};


template<typename T>
void print(T obj) {
	cout << "Template print: " << obj << endl;
}


void print(int n) {
	cout << "Non-template print(int): " << n << endl;
}
