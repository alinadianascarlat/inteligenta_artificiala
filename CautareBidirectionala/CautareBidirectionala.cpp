#include <iostream>
#include <string>

using namespace std;
class FindPath {
private:
	string names[20] = { "Arad","Bucuresti","Craiova","Drobeta","Eforie","Fagaras","Giurgiu","Harsova",+
		"Iasi","Lugoj","Mehadia","Neamt","Oradea","Pitesti","Ramnicul Valcea","Sibiu","Timisoara","Urziceni","Vaslui","Zerind" };
	int a[20][20];
	int parentsBS[20];
	int parentsDS[20];

	int startNode;
	int targetNode;
	bool solutionFound;
	int solutionNode;

	void printSolutionRec(int parents[20], int startNode, int node) {
		if (node != startNode) {
			printSolutionRec(parents, startNode, parents[node]);
		}

		cout << names[node] << " ";
	}


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

	void bidirectionalSearch() {
		int visitedBS[20];
		int visitedDS[20];
		int nodesBS[20];
		int nodesDS[20];
		int nodesPosBS = 0;
		int nodesPosDS = 0;
		solutionFound = false;

		for (int i = 0; i < 20; i++) {
			visitedBS[i] = 0;
			visitedDS[i] = 0;
			parentsBS[i] = -1;
			parentsDS[i] = -1;
		}

		nodesBS[nodesPosBS] = startNode;
		nodesPosBS++;
		visitedBS[startNode] = 1;

		nodesDS[nodesPosDS] = targetNode;
		nodesPosDS++;
		visitedDS[targetNode] = 1;

		while (!solutionFound) {
			int nodeBS = nodesBS[0];

			for (int i = 0; i < nodesPosBS; i++) {
				nodesBS[i] = nodesBS[i + 1];
			}
			nodesPosBS--;

			int nodeDS = nodesDS[nodesPosDS - 1];
			nodesPosDS--;

			for (int k = 0; k < nodesPosBS; k++) {
				for (int i = 0; i < nodesPosDS; i++) {
					if (nodesBS[k] == nodesDS[i]) {
						solutionFound = true;
						solutionNode = nodesBS[k];
						break;
					}
				}
				if (solutionFound)
					break;
			}

			if (!solutionFound) {
				for (int i = 0; i < 20; i++) {
					if (a[i][nodeBS] != 0 && visitedBS[i] == 0) {
						nodesBS[nodesPosBS] = i;
						nodesPosBS++;
						parentsBS[i] = nodeBS;
						visitedBS[i] = 1;
					}

					if (a[i][nodeDS] != 0 && visitedDS[i] == 0) {
						nodesDS[nodesPosDS] = i;
						nodesPosDS++;
						parentsDS[i] = nodeDS;
						visitedDS[i] = 1;
					}
				}
			}
		}
	}

	void printSolution() {
		if (solutionFound) {
			this->printSolutionRec(parentsBS, startNode, solutionNode);
			int node = parentsDS[solutionNode];
			while (parentsDS[node] != targetNode && parentsDS[node] != -1) {
				cout << names[node] << " ";
				node = parentsDS[node];
			}
			cout << names[targetNode];
			cout << endl;
		}
		else {
			cout << "Nu exista solutie!" << endl;
		}
	}
};

int main()
{
	FindPath* findPath = new FindPath();
	findPath->readStartEndCities();
	findPath->initializeAdiacenceMatrix(); // initializeaza matricea de adiacenta

	cout << "Cautare bidirectionala" << endl;
	findPath->bidirectionalSearch();
	findPath->printSolution();
	cout << endl;
}
