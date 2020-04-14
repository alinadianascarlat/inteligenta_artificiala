#include <iostream>
#include <string>

using namespace std;
class FindPath {
private:
	string names[20] = { "Arad","Bucuresti","Craiova","Drobeta","Eforie","Fagaras","Giurgiu","Harsova",+
		"Iasi","Lugoj","Mehadia","Neamt","Oradea","Pitesti","Ramnicul Valcea","Sibiu","Timisoara","Urziceni","Vaslui","Zerind" };
	int a[20][20];
	int c[20][20];
	int parents[20];
	int h[20][20];
	int startNode;
	int targetNode;
	bool solutionFound;

	void printSolutionRec(int node) {
		if (node != startNode) {
			printSolutionRec(parents[node]);
		}

		cout << names[node] << " ";
	}

	void sortCostUniform(int* nodesTail, int nodesTailPos, int* cost) {
		for (int i = 0; i < nodesTailPos; i++) {
			int min = cost[i];
			int pozMin = i;

			for (int j = i; j < nodesTailPos; j++) {
				if (cost[j] < min) {
					pozMin = j;
					min = nodesTail[j];
				}
			}

			int tmp = nodesTail[i];
			nodesTail[i] = nodesTail[pozMin];
			nodesTail[pozMin] = tmp;
		}
	}

	void sortareCautareGreedy(int nodes[20], int numarDeNoduri) {
		// sortez tabloul nodes descrescator in functie de h

		for (int i = 0; i < numarDeNoduri; i++) {
			for (int j = i + 1; j < numarDeNoduri; j++)
				if (h[nodes[i]] < h[nodes[j]]) {
					int max = nodes[i];
					nodes[i] = nodes[j];
					nodes[j] = max;
				}
		}
	}

	void sortareCautareAStelat(int nodes[20], int numarDeNoduri, int cost[20]) {
		for (int i = 0; i < numarDeNoduri; i++) {
			for (int j = i + 1; j < numarDeNoduri; j++)
				if ((cost[nodes[i]] + h[startNode][nodes[i]]) < (h[startNode][nodes[j]] + cost[nodes[j]])) {
					int max = nodes[i];
					nodes[i] = nodes[j];
					nodes[j] = max;
				}
		}
	}

	void initializareMatriceDeAdiacenta()
	{
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				a[i][j] = 0;
			}
		}
		a[0][19] = 75;
		a[0][15] = 140;
		a[0][16] = 118;
		a[1][6] = 90;
		a[1][13] = 101;
		a[1][5] = 211;
		a[1][17] = 85;
		a[2][13] = 138;
		a[2][14] = 146;
		a[2][3] = 120;
		a[3][10] = 75;
		a[4][7] = 80;
		a[5][15] = 99;
		a[7][17] = 98;
		a[8][18] = 92;
		a[8][11] = 87;
		a[9][10] = 70;
		a[9][16] = 111;
		a[12][19] = 71;
		a[12][15] = 151;
		a[13][14] = 97;
		a[14][15] = 80;
		a[17][18] = 142;

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (a[i][j] != 0)
					a[j][i] = a[i][j];
			}
		}
	}

	void initializareMatriceTrafic()
	{
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				c[i][j] = 0;
			}
		}
		c[0][19] = 800;
		c[0][15] = 1200;
		c[0][16] = 1100;
		c[1][6] = 400;
		c[1][13] = 101;
		c[1][5] = 1200;
		c[1][17] = 700;
		c[2][13] = 1600;
		c[2][14] = 1300;
		c[2][3] = 900;
		c[3][10] = 600;
		c[4][7] = 800;
		c[5][15] = 900;
		c[7][17] = 900;
		c[8][18] = 1200;
		c[8][11] = 700;
		c[9][10] = 400;
		c[9][16] = 1000;
		c[12][19] = 700;
		c[12][15] = 2500;
		c[13][14] = 1300;
		c[14][15] = 800;
		c[17][18] = 1400;
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (c[i][j] != 0)
					c[j][i] = c[i][j];
			}
		}
	}

	void initializareMatriceAproximari()
	{

		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++) {
				h[i][j] = costUniform(i, j);
			}
	}

public:
	int iterativeLimit;

	void intializare() {
		initializareMatriceDeAdiacenta();
		initializareMatriceTrafic();
		initializareMatriceAproximari();
	}

	void readStartEndCities() {
		cout << "Introduceti numarul corespunzator orasului de plecare: " << endl;
		for (int i = 0; i < 20; i++) {
			cout << i << " - " << names[i] << endl;
		}
		cin >> this->startNode;

		cout << "Introduceti numarul corespunzator orasului de sosire: " << endl;
		for (int i = 0; i < 20; i++) {
			if (i != this->startNode) {
				cout << i << " - " << names[i] << endl;
			}
		}
		cin >> this->targetNode;
	}

	int costUniform(int startNode, int targetNode) {
		int cost[20];
		int nodesTail[20];
		int nodesTailPos = 0;
		bool solutionFound = false;

		for (int i = 0; i < 20; i++) {
			cost[i] = 0;
		}

		nodesTail[nodesTailPos] = startNode;
		nodesTailPos++;
		cost[startNode] = 0;

		while (!solutionFound && nodesTailPos != 0) {
			sortCostUniform(nodesTail, nodesTailPos, cost);
			int node = nodesTail[0];

			for (int i = 0; i < nodesTailPos; i++) {
				nodesTail[i] = nodesTail[i + 1];
			}
			nodesTailPos--;

			if (node == targetNode) {
				solutionFound = true;
			}
			else {
				for (int i = 0; i < 20; i++) {
					if (a[i][node] != 0 && (cost[i] == 0 || cost[i] > cost[node] + a[i][node])) {
						nodesTail[nodesTailPos] = i;
						nodesTailPos++;
						cost[i] = cost[node] + a[i][node];
					}
				}
			}
		}

		return cost[targetNode];
	}

	void cautareGreedy() {
		int visitedCities[20];
		int nodesStack[20];
		int nodesStackPos = 0;
		solutionFound = false;

		for (int i = 0; i < 20; i++) {
			visitedCities[i] = 0;
			parents[i] = -1;
		}
		nodesStack[nodesStackPos] = startNode;
		nodesStackPos++;
		visitedCities[startNode] = 1;

		while (!solutionFound) {
			sortareCautareGreedy(nodesStack, nodesStackPos);

			int node = nodesStack[nodesStackPos - 1];
			nodesStackPos--;

			if (node == targetNode) {
				solutionFound = true;
			}
			else
			{
				for (int i = 0; i < 20; i++) {
					if (a[i][node] != 0 && visitedCities[i] == 0) {
						nodesStack[nodesStackPos] = i;
						nodesStackPos++;
						parents[i] = node;
						visitedCities[i] = 1;
					}
				}
			}
		}

	}

	void cautareAStelat() {
		int cost[20];
		int visitedCities[20];
		int nodesStack[20];
		int nodesStackPos = 0;
		solutionFound = false;

		for (int i = 0; i < 20; i++) {
			cost[i] = 0;
			visitedCities[i] = 0;
			parents[i] = -1;
		}

		nodesStack[nodesStackPos] = startNode;
		nodesStackPos++;
		visitedCities[startNode] = 1;

		while (!solutionFound) {
			sortareCautareAStelat(nodesStack, nodesStackPos, cost);

			int node = nodesStack[nodesStackPos - 1];
			nodesStackPos--;

			if (node == targetNode) {
				solutionFound = true;
			}
			else
			{
				for (int i = 0; i < 20; i++) {
					if (a[i][node] != 0 && visitedCities[i] == 0) {
						nodesStack[nodesStackPos] = i;
						nodesStackPos++;
						parents[i] = node;
						visitedCities[i] = 1;
						cost[i] = cost[node] + a[i][node];
					}
				}
			}
		}

	}

	void printSolution() {
		if (solutionFound) {
			this->printSolutionRec(targetNode);
			cout << endl;
		}
		else {
			cout << "Nu exista solutie!" << endl;
		}
	}

	void printTime() {
		if (solutionFound) {
			int dist = 0;
			double totalTime = 0;

			int node = targetNode;

			while (node != startNode) {
				dist += a[node][parents[node]];

				double x = (double)c[node][parents[node]] / (double)a[node][parents[node]];
				double v;
				if (x >= 10)
					v = 100.0 * 10.0 / x;
				else
					v = 100;
				totalTime += (double)a[node][parents[node]] / (double)v;

				node = parents[node];
			}

			cout << "Km parcursi pe ruta gasita: " << dist << endl;

			int hours = int(totalTime);
			int minutes = (totalTime - hours) * 60;

			cout << "Timp: " << hours << "h si " << minutes << " minute" << endl;
		}

	}
};

int main()
{
	FindPath* findPath = new FindPath();
	findPath->readStartEndCities();
	findPath->intializare(); // initializeaza matricea de adiacenta

	cout << "Cautare Greedy" << endl;
	findPath->cautareGreedy();
	findPath->printSolution();
	findPath->printTime();
	cout << endl;

	cout << "Cautare A*" << endl;
	findPath->cautareAStelat();
	findPath->printSolution();
	findPath->printTime();
	cout << endl;
}
