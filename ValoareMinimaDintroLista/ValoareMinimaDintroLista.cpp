//4. Valoarea minima dintr o lista de nr.

#include <iostream>
using namespace std;

int main()
{

    int v[50], i, n, min;

    cout << " n = ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "v[" << i << "]=";
        cin >> v[i];
    }

    min = v[0];
    for (i = 1; i < n; i++) {
        if (v[i] < min) {
            min = v[i];
        }
    }
    cout << "Minimul este " << min;
    return 0;
}

