// 5. Sa se elimine un numar aflat pe o anumita pozitie intr-o lista

#include<iostream>
using namespace std;

int main() {
	int v[20], n;
	cout << "n = ";
	cin >> n;


	for (int i = 1; i <= n; i++) {
		cin >> v[i];

	}
	int k;
	cin >> k;

	for (int i = k; i < n - 1; i++) {
		v[i] = v[i + 1];
	}
	for (int i = 1; i <= n; i++) {
		cout << v[i] << "";
	}
}