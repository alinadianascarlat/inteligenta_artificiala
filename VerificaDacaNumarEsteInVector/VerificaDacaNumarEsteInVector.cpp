//Verificam daca un nr este intr un vector


#include <iostream>
using namespace std;

int main()
{

    int v[30], i, n, m;
    cout << " n = ";
    cin >> n;
    cout << " m = ";
    cin >> m;
    for (i = 0; i < n; i++) {
        cout << " v [" << i << " ] \n";

    }
    if (n == m) {
        cout << " Numarul face parte din vector ";
    }
    else
        cout << "Numarul nu face parte din vector ";
}

