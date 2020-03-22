#include<iostream>

using namespace std;

class Coada {

public:
	int a[40];
	int index;

	void adauga(int n) {
		a[index] = 0;
		index++;


    }
};

int main() {
	Coada* c = new Coada();
	c->adauga(2);
	c->adauga(4);

	/*cout << c->scoate();
	cout << c->scoate();
	cout << c->goala();*/

}