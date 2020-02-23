// 11. Sa se genereze un numar intre 0 si 100 in C.

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
