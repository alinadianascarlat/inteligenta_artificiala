//5. Sa se elimine un numar aflat pe o anumita pozitie intr - o lista.

#include<iostream>

using namespace std;

void afisare(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "v[" << i << "] = " << a[i] << endl;
	}
}

void citire(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "v[" << i << "] = ";
		cin >> a[i];
	}
}

int  main() {
	int n, i, v[20], poz;

	cout << "n = ";
	cin >> n;

	cout << "Introducem pozitia de pe care eliminam nr: ";
	cin >> poz;

	// n = 3
	citire(v, n);

	// 5 6 7 9 4
	// poz 2 => 5 7 9 4
	for (i = poz; i < n; i++) {
		v[i] = v[i + 1];
	}

	n = n - 1;
	// n = 2

	afisare(v, n);
}
