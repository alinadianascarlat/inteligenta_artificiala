#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int distanta[20][20] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{0, 596, 550, 574, 555, 538,394, 426, 419, 330, 282, 161, 126, 248, 436, 349, 406, 213, 278, 225},
	{0, 0, 67, 135, 250, 304, 331, 170, 216, 271, 333, 434, 485, 544, 369, 429, 463, 660, 752, 815},
	{0, 0, 0, 183, 298, 352, 303, 146, 148, 219, 305, 388, 457, 516, 326, 387, 420, 618, 710, 768},
	{0, 0, 0, 0, 115, 169, 278, 147, 263, 249, 311, 412, 463, 463, 478, 444, 538, 671, 763, 792},
	{0, 0, 0, 0, 0, 52, 239, 263, 378, 350, 273, 415, 429, 394, 593, 531, 646, 674, 766, 780},
	{0, 0, 0, 0, 0, 0, 217, 316, 417, 327, 256, 399, 406, 353, 575, 509, 691, 651, 743, 758},
	{0, 0, 0, 0, 0, 0, 0, 160, 200, 116, 113, 232, 268, 293, 358, 292, 407, 490, 583, 612},
	{0, 0, 0, 0, 0, 0, 0, 0, 119, 101, 163, 264, 315, 374, 334, 297, 390, 523, 615, 644},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 89, 200, 257, 352, 411, 214, 247, 308, 486, 578, 638},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 112, 168, 262, 321, 261, 195, 310, 426, 519, 548},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 142, 155, 236, 358, 289, 441, 401, 493, 507},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 149, 205, 319, 228, 299, 258, 350, 380},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 123, 468, 378, 448, 318, 404, 351},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 524, 434, 504, 434, 504, 451},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 122, 144, 341, 433, 520},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 131, 254, 346, 432},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 271, 364, 434},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 92, 178},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 124},
};

int* initializare(int n) {
	int* configuratie = new int[n];
	int* M = new int[n];
	for (int i = 0; i < n; i++) {
		M[i] = i + 1;
	}
	int i = 0;
	int lungimeM = n;

	while (lungimeM > 0) {
		int g = rand() % lungimeM;
		configuratie[i++] = M[g];

		for (int j = g; j < lungimeM; j++) {
			M[j] = M[j + 1];
		}

		lungimeM--;
	}
	return configuratie;
}

int evaluare(int* configuratie, int n) {
	int distanta_totala = 0;
	for (int i = 1; i < n - 1; i++) {
		distanta_totala = distanta_totala + distanta[configuratie[i]][configuratie[i + 1]];
	}

	distanta_totala = distanta_totala + distanta[configuratie[n - 1]][configuratie[0]];

	return distanta_totala;
}

int* variatie(int* v, int n) {
	int* configuratie = new int[n];
	for (int i = 0; i < n; i++) {
		configuratie[i] = v[i];
	}

	//int p, pm;
	int temp;

	for (int j = 0; j < n; j++) {
		//p = rand(1);
		//if (p < pm) {

		int x = rand() % n;

		while (x == j) {
			x = rand() % n;

			temp = configuratie[x];
			configuratie[x] = configuratie[j];
			configuratie[j] = temp;
		}
	}
	return configuratie;
}


void afisare(int* v, int n) {
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	int n = 20;
	int numarApeluriEvaluare = 0;
	int* configuratie;
	double timpTrecut;

	time_t start, end;

	time_t t;
	srand((unsigned)(time(&t)));

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (distanta[i][j] != 0)
				distanta[j][i] = distanta[i][j];
		}
	}

	int* configuratie1;
	int* ceaMaiBunaConfiguratie = NULL;

	int evaluareTinta = -1;

	time(&start);

	do {
		configuratie = initializare(n);
		numarApeluriEvaluare++;

		int eval_curent;
		numarApeluriEvaluare++;
		for (int i = 0; i < 1000; i++) {
			eval_curent = evaluare(configuratie, n);
			if (eval_curent < evaluareTinta || evaluareTinta == -1) {
				evaluareTinta = eval_curent * 0.8; // incercam sa imbunatatim cu 20%
				ceaMaiBunaConfiguratie = configuratie;
			}
			configuratie1 = variatie(configuratie, n);
			numarApeluriEvaluare++;
			if (evaluare(configuratie1, n) < eval_curent) {
				evaluareTinta = eval_curent * 0.8; // incercam sa imbunatatim cu 20%
				configuratie = configuratie1;
				ceaMaiBunaConfiguratie = configuratie1;
			}
		}
		time(&end);

		timpTrecut = end - start;
		numarApeluriEvaluare += 2;
	} while ((evaluareTinta < evaluare(configuratie, n)) && (numarApeluriEvaluare < 1000000) && (timpTrecut < 3));

	cout << "Configuratie finala: ";
	afisare(ceaMaiBunaConfiguratie, n);
	cout << "Evaluare configuratie finala: " << evaluare(ceaMaiBunaConfiguratie, n) << endl;
	cout << "Functia evaluare s-a apelat de: " << numarApeluriEvaluare << endl;
	cout << "Timpul de executie: " << timpTrecut << endl;

	cout << endl;
	cout << "80% din evaluare configuratie finala: " << evaluare(ceaMaiBunaConfiguratie, n) * 0.8 << endl;
	cout << "Evaluare tinta: " << evaluareTinta << endl;
}
