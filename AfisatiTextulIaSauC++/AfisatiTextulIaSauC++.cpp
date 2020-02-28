//12. Afisati cu o probabilitate de 0.5 (50 % sanse) textul „Inteligenta Artificiala”.In celalalt caz
//afisati „Limbajul C”.


#include<iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;

int  main() {
	time_t t;
	srand((unsigned)(time(&t)));
	int g = rand() % 2;
	if (g == 0)
		cout << "Limbajul C";
	if (g == 1)
		cout << "Inteligenta artificiala";
}

