// 11. Cum generezi un nr de la 0 la 100

#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cout << " n = ";
    cin >> n;
    for (i = 0; i < 10; i++) {
        cout << (rand() % 101) << " \t";
    }


    return 0;
}
