// 11. Sa se genereze un numar intre 0 si 100 in C.

#include <iostream>
#include <time.h> 

using namespace std;

int main()
{
    srand(time(NULL));

    cout << (rand() % 100) + 1;
    
    return 0;
}
