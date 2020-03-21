//6. Sa se elimine un numar dat dintr-o lista data.


// lista = 4 5 9 7 34 123 12 54 654 56 67 76 878 79 889 89 898 98 09 909 90 68 34 243 23 2 23 454 7567 23 45 
// numarul = 2

#include<iostream>

using namespace std;

void afisare(int a[], int n) {
	for ( int i = 0; i < n; i++) {
		cout << "a[" << i << "]=" << a[i] <<endl;

	}
}

void citire(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}
int main() {

	int i, n,v[20];
	int poz;

	cout << "n = ";
	cin >> n;

	cout << "Afiseaza nr pozitiei:";
	cin >> poz;

	citire(v, n);
	for (i = 0; i < n; i++) {
		if (n == v[i]) {
			poz = i;
			
		}
	}
	

	for (i = 0; i < n; i++) {
		v[i] = v[i + 1];
	}
	n = n - 1;
	afisare(v, n);
	
	
}
















// cazuri limita: 
// 1. numarul nu exista in lista => afiseaza mesaj ca nu exista
// 2. numarul exista de mai multe ori in lista => elimina toate prezentele in lista