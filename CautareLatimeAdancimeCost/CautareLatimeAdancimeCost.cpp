#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

string nume[20] = { "Arad","Bucuresti","Craiova","Drobeta","Eforie","Fagaras","Giurgiu","Hirsova","Iasi","Lugoj","Mehadia","Neamt","Oradea","Pitesti","Rimnicu Valcea","Sibiu","Timisoara","Urziceni","Vaslui","Zerind" };
//                   0         1          2         3          4         5         6         7       8       9       10       11       12       13          14          15       16          17        18         19
int n = 20, i, j, k, l;
int oras_start = 0, oras_dest = 1;
int nr_noduri = 0;
int gasit = 0, noduri[20], vizitat[20], parinte[20], nod;
int a[20][20]; //matricea de adiacenta.


void main() {
	a[0][16] = 1;
	a[0][15] = 1;
	a[0][19] = 1;
	a[1][5] = 1;
	a[1][6] = 1;
	a[1][17] = 1;
	a[1][13] = 1;
	a[2][3] = 1;
	a[2][14] = 1;
	a[2][13] = 1;
	a[3][10] = 1;
	a[4][7] = 1;
	a[5][15] = 1;
	a[7][17] = 1;
	a[8][11] = 1;
	a[8][18] = 1;
	a[9][10] = 1;
	a[9][16] = 1;
	a[12][19] = 1;
	a[12][15] = 1;
	a[13][14] = 1;
	a[14][15] = 1;
	a[17][18] = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (a[i][j] == 1)
				a[j][i] = 1;
	cout << "Introduceti orasul caruia ii cautam vecinii:";
	cin >> l;
	for (i = 0; i < n; i++)
		if (a[l][i] == 1)
			cout << nume[i] << " ";
	cout << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	//Algoritm de cautare in adancime
	for (i = 0; i < n; i++)

		vizitat[i] = 0; //toate orasele sunt nevizitate

	noduri[0] = oras_start; //Adaugam in lista noduri orasul de plecare
	nr_noduri++;

	vizitat[oras_start] = 1; //Adaugam in lista noduri orasul de plecare

	while (gasit != 1 && nr_noduri != 0) {
		nod = noduri[0]; //stocam primul element din noduri in variabila nod

		for (i = 0; i < nr_noduri - 1; i++) //Eliminam primul element din noduri
			noduri[i] = noduri[i + 1];//Stocam primul element din noduri in variabila nod
		nr_noduri--;

		if (nod == oras_dest) //Daca testare_tinta[problema] se aplica la stare(nod) atunci

			gasit = 1; //Solutia este gasita facem variabila booleana gasit adevarata 
		else
			for (i = 0; i < nr_noduri - 1; i++)
				if (a[nod][i] == 1 && vizitat[i] == 0) //daca orasul i este conectat de orasul nod si nevizitat
				{
					for (j = nr_noduri; j > 0; j--)
						noduri[j] = noduri[j - 1];
					noduri[0] = i; //Adaugam la inceput in noduri orasele nevizitate care sunt conectate de nod
					nr_noduri++;
					vizitat[i] = 1;//Orasele adaugate sunt marcate ca vizitate
					parinte[i] = nod;
				}
	}



	//algorituml de cautare in latime

	for (i = 0; i < n; i++) {
		noduri[nr_noduri++] = oras_start;

		for (i = 0; i < n; i++) {
			vizitat[i] = 0;
			vizitat[oras_start] = 1;//marcam orasul start ca vizitat

			while (gasit != 1 && nr_noduri != 0) {
				nod = noduri[0];
				for (i = 0; i < nr_noduri; i++)
					noduri[i] = noduri[i + 1];//stocam primul element din noduri in variabila nod
				nr_noduri--;

				if (nod == oras_dest)
					gasit = 1;
				else
					for (i = 0; i < nr_noduri - 1; i++)
						if (a[nod][i] == 1 && vizitat[i] == 0) //daca orasul i este conectat de orasul nod si nevizitat
						{
							for (j = nr_noduri; j > 0; j--)
								noduri[j] = noduri[j - 1];
							noduri[0] = i; //Adaugam la inceput in noduri orasele nevizitate care sunt conectate de nod
							nr_noduri++;
							vizitat[i] = 1;//Orasele adaugate sunt marcate ca vizitate
							parinte[i] = nod;
						}
			}
		}
	}
	
}
