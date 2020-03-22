#include <iostream>
#include <string>

using namespace std;
class FindPath {
private:
	string names[20] = { "Arad","Bucuresti","Craiova","Drobeta","Eforie","Fagaras","Giurgiu","Harsova",+
		"Iasi","Lugoj","Mehadia","Neamt","Oradea","Pitesti","Ramnicul Valcea","Sibiu","Timisoara","Urziceni","Vaslui","Zerind" };
	int a[20][20];
	int parents[20];
	int startNode;
	int targetNode;

public:
	void initializeAdiacenceMatrix() {
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

	void breathSearch() {
		int visitedCities[20];
		int nodesTail[20];
		int nodesTailPos = 0;
		bool solutionFound = false;

		for (int i = 0; i < 20; i++) {
			visitedCities[i] = 0;
			parents[i] = -1;
		}

		nodesTail[nodesTailPos] = startNode;
		nodesTailPos++;
		visitedCities[startNode] = 1;

		while (!solutionFound && nodesTailPos != 0) {
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
					if (a[i][node] != 0 && visitedCities[i] == 0) {
						nodesTail[nodesTailPos] = i;
						nodesTailPos++;
						parents[i] = node;
						visitedCities[i] = 1;
					}
				}
			}
		}
	}

	void depthSearch() {
		int visitedCities[20];
		int nodesStack[20];
		int nodesStackPos = 0;
		bool solutionFound = false;

		for (int i = 0; i < 20; i++) {
			visitedCities[i] = 0;
			parents[i] = -1;
		}
		nodesStack[nodesStackPos] = startNode;
		nodesStackPos++;
		visitedCities[startNode] = 1;

		while (!solutionFound) {
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

	void costUniform() {
		int cost[20];
		int nodesTail[20];
		int nodesTailPos = 0;
		bool solutionFound = false;

		for (int i = 0; i < 20; i++) {
			cost[i] = 0;
			parents[i] = -1;
		}

		nodesTail[nodesTailPos] = startNode;
		nodesTailPos++;
		cost[startNode] = 0;

		while (!solutionFound && nodesTailPos != 0) {
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
						parents[i] = node;
						cost[i] = cost[node] + a[i][node];
					}
				}
			}
		}
	}

	void printSolution() {
		this->printSolutionRec(targetNode);
		cout << endl;
	}

	void printTime() {
		int dist = 0;

		int node = targetNode;

		while (node != startNode) {
			dist += a[node][parents[node]];
			node = parents[node];
		}

		cout << "Time = " << dist / 80.0 << " hours" << endl;
	}

private:
	void printSolutionRec(int node) {
		if (node != startNode) {
			printSolutionRec(parents[node]);
		}

		cout << names[node] << " ";
	}
};

int main()
{
	FindPath* findPath = new FindPath();
	findPath->readStartEndCities();
	findPath->initializeAdiacenceMatrix(); // initializeaza matricea de adiacenta

	cout << "Cautare in latime" << endl;
	findPath->breathSearch(); // cauta in latime
	findPath->printSolution(); // afiseaza solutia daca exista, altfel afiseaza un mesaj ca solutia nu exista
	findPath->printTime();

	cout << "Cautare in adancime" << endl;
	findPath->depthSearch(); // cauta solutie in adancime
	findPath->printSolution();
	findPath->printTime();

	cout << "Cautare Cost Uniform" << endl;
	findPath->costUniform(); // cauta solutie cost uniform
	findPath->printSolution();
	findPath->printTime();
}
