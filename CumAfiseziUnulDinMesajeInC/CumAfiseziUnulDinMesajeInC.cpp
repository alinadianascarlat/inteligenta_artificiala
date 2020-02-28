//13. Oferiti sanse egale afisarii unuia din cele trei texte in C:
//a.Inteligenta Artificiala
//b.Limbajul C
//c.Programare Web

#include<iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;

int main() {
	time_t t;
	srand((unsigned)(time(&t)));
	int g = rand()%3;
	if (g == 0)
		cout << "Inteligenta artificiala";
	if (g == 1)
		cout << "Limbajul C";
	if (g == 2)
		cout << "Programare Web";
}