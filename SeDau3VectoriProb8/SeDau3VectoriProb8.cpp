#include<iostream>
#include<conio.h>

using namespace std;

void main() {
	int a[20], b[20],c[20], i, n;
	cout << " n = ";
	cin >> n;
	for (i = 0; i < n; i++) 
		cout << "a[" << i << "]=";
		cin >> a[i];

		int adevarat = 1;
		for (i = 0; i < n; i++) {
			if((a[i] < b[i]) //(b[i]>=c[i]))
				adevarat = 0;
				if(adevarat ==1)
					cout << "adevarat";
				else
					cout <<"fals";
	}
}