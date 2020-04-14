#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int v[200];
int n;

bool vecinValid(int val)
{
	for (int i = 0; i < n; i++)
	{
		if (v[i] == val)
			return false;
	}

	return true;
}

void Permuta()
{
	time_t t;
	srand((unsigned)(time(&t)));
	int curent = -1;

	while (curent < n-1)
	{
		int randVal = rand() % n;
		
		if (vecinValid(randVal))
		{
			curent++;
			v[curent] = randVal;
		}
	}
}

int main() {
	cout << "n = ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		v[i] = -1;
	}

	Permuta();

	cout << "O permutare: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << " ";
	}
}
