//5. Sa se elimine un numar aflat pe o anumita pozitie intr - o lista.

#include<iostream>
using namespace std;
int  main() {

	int n, i, p, v[20];

	cout << " n = ";
	cin >> n;
	

	for ( i = 0; i < n; i++) {
		cout << "v[" << i << "]=";
		cin >> v[i];
	}

	for ( i = 0; i < n; i++) {
		v[i] = v[i + 1];
		n--;
	}
	for (i = 0; i < n; i++) {
		cout << v[i];
	}
}
