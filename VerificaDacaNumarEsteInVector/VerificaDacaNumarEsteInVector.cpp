// 2. Se da o lista de numere.Sa se verifice daca un anumit numar exista sau nu in aceasta lista


#include <iostream>
using namespace std;

int main()
{
	int v[30], i, n, m;
	cout << " n = ";
	cin >> n;

	cout << " m = ";
	cin >> m;

	for (i = 0; i < n; i++) {
		cout << "v[" << i << "] = ";
		cin >> v[i];
	}

	bool gasit = false;
	for (i = 0; i < n; i++) {
		if (v[i] == m) {
			gasit = true;
			break;
		}
	}

	if (gasit) {
		cout << "Numarul este in vector \n";
	}
	else {
		cout << "Numarul nu este in vector \n";
	}
}
