
#include<iostream>
using namespace std;

int x1[100], n1, nrsol1 = 0;

void Afisare()
{
    int i;
    for (i = 1; i <= n1; i++)
        cout << x1[i] << " ";
    cout << endl;
    nrsol1++;
}

int Valid(int k)
{
    for (int i = 1; i <= k - 1; i++) {
        if (x1[k] == x1[i])
            return 0;
    }
    return 1;
}

void BackRec1(int k)
{
    int i;
    for (i = 1; i <= n1; i++)
    {
        x1[k] = i;
        if (Valid(k)) {
            if (k == n1) 
                Afisare();
            else 
                BackRec1(k + 1);
        }
    }
}

int main()
{
    cout << "Permutarile primelor n numere naturale (n>8)" << endl;
    cout << "Dati valoarea lui n: "; 
    cin >> n1;
    
    BackRec1(1);
    
    cout << "Numar solutii: " << nrsol1;
    
    return 0;
}