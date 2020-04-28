#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int* initializare(int n) {
	int* configuratie = new int[n];
	int* M = new int[n];
	for (int i = 0; i < n; i++) {
		M[i] = i + 1;
	}
	int i = 0;
	int lungimeM = n;

	time_t t;
	srand((unsigned)(time(&t)));

	while (lungimeM > 0) {
		int g = rand() % lungimeM;
		configuratie[i++] = M[g];

		for (int j = g; j < lungimeM; j++) {
			M[j] = M[j + 1];
		}

		lungimeM--;
	}
	return configuratie;
}

int evaluare(int* configuratie, int n) {
	int erori = 0;
	for (int i = 1; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (abs(configuratie[i] - configuratie[j]) == abs(i - j)) {
				erori++;
			}
		}
	}
	return erori;
}

int* perturbare(int* v, int n) {
	int* configuratie = new int[n];
	for (int i = 0; i < n; i++) {
		configuratie[i] = v[i];
	}

	int x = rand() % n;
	int y = rand() % n;
	while (x == y) {
		y = rand() % n;
	}
	int temp = configuratie[x];
	configuratie[x] = configuratie[y];
	configuratie[y] = temp;
	return configuratie;
}

int main() {
	int n;
	cout << "n = ";
	cin >> n;

	cout << "Permutare:" << endl;
	int* p = initializare(n);

	for (int i = 0; i < n; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
	cout << "Evaluarea permutarii: " << evaluare(p, n) << endl;

	int* p1 = perturbare(p, n);
	for (int i = 0; i < n; i++) {
		cout << p1[i] << " ";
	}
	cout << endl;
	cout << "Evaluarea perturbarii: " << evaluare(p1, n) << endl;
}
