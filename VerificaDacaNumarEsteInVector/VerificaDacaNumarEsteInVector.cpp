//Verificam daca un nr este intr un vector

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
