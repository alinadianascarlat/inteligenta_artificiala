#include<iostream>

using namespace std;

class Stack {
public:
	int a[40];
	int index = 0;

	void push(int n) {
		a[index] = n;
		index++;
	}

	int pop() {
		int element = a[index - 1];
		index--;
		return element;
	}

	int empty() {
		if (index == 0)
			return true;
		else
			return false;
	}
};

int main() {
	Stack* s = new Stack();
	s->push(3);
	s->push(12);
	s->push(29);

	cout << s->pop() << endl;
	cout << s->empty() << endl;

	cout << s->pop() << endl;
	cout << s->empty() << endl;

	cout << s->pop() << endl;
	cout << s->empty() << endl;
}
