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
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n + 1; j++) {
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

void afisare(int* v, int n) {
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	int n = 8;
	time_t start, end;

	time_t t;
	srand((unsigned)(time(&t)));

	int numarApeluriEvaluare = 0;
	int* configuratie;
	double timpTrecut;
	 
	time(&start);

	do {
		configuratie = initializare(n); // tablou cu posibila solutie initiala pentru dame
		afisare(configuratie, n);
		cout << evaluare(configuratie, n) << endl;
		numarApeluriEvaluare++;
		for (int i = 0; i < 1000; i++) {
			int eval_curent = evaluare(configuratie, n); // cate dame se ataca
			int* configuratie1 = perturbare(configuratie, n); // obtine o alta permutare
			numarApeluriEvaluare++;
			if (evaluare(configuratie1, n) < eval_curent) {
				configuratie = configuratie1;
			}
		}
		
		time(&end);

		timpTrecut = end - start;
	} while ((evaluare(configuratie, n) != 0) || (numarApeluriEvaluare > 1000000) || timpTrecut > 3);

	afisare(configuratie, n);
	cout << evaluare(configuratie, n) << endl;
	cout << "Functia evaluare s-a apelat de: " << numarApeluriEvaluare << endl;
	cout << "Timpul de executie: " << timpTrecut << endl;
}
