#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define N 8;

using namespace std;

void permutare(int d[]) {
	int n = N, a[N];
	for (int i = 0; i < N; i++) {
		a[i] = i + 1;
	}
	while (n > 0) 
		for (int i = 0; i < N; i++) {
			int g = rand() % n;
			d[i] = a[g];
			a[g] = a[n - 1];
			n--;
		}
	
}


int main() {
	int d[N];
	srand(time(NULL));
	permutare(d);
	cout << "Numerele sunt:" << endl;
	for (int i = 0; i < N; i++)
		cout << d[i] << " ";
	return 0;
}

