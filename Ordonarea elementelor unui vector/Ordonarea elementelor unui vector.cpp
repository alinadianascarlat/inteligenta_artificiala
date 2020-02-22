//9. Ordonarea elementelor dintr - o lista.

#include <iostream>
using namespace std;
int main()
{
    int v[20], i, n, temp;
    cout << "n = ";
    cin >> n;
    for ( int i = 0; i < n; i++) {
        cout << " v[ " << i << "] =";
        cin >> v[i];
    }
    for( int i = 0; i < n -1; i++)
        for( int j = i + 1; j < n; j++)
            if (v[i] > v[j]) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
    for ( int i = 0; i < n; i++) {
        cout << " v[ " << i << "] \n";
    }
}














