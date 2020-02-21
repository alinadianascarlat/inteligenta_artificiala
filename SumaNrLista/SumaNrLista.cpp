
// 1. Se da o lista de numere. Sa se calculeze suma acestora. 

#include <iostream>
#include <conio.h>

using namespace std;

void main()
{
	int v[20], i, n;

	cout << "n = ";
	cin >> n;

	for (i = 0; i < n; i++) {
		cout << "v[" << i << "] = ";
		cin >> v[i];

	}
	int  sum = 0;
	for (i = 0; i < n; i++) {
		sum = sum + v[i];
	}
	cout << "sum = " << sum << "\n";
}
