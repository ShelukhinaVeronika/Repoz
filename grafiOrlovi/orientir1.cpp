//1. Дан ориентированный граф. Вывести количество вершин, смежных с данной.
#include <iostream>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

bool isWeigth(int w) {
	if (w != 1) return 1;
	else return 0;
}

int main() {
	setlocale(LC_ALL, "RU");
	/* int n, x;
	 cout << "Введите n: ";
	 cin >> n;
	 vector<vector <int>> graf(n);
	 cout << "Введите матрицу смежности: ";
	 for (int i = 0; i < n; i++) {
		 for (int j = 0; j < n; j++) {
			 cin >> x;
			 if (x != 0){
				 graf[i].push_back(j);
			 }
		 }
	 }
	 int vert;
	 cout << "Введите номер вершины: ";
	 cin >> vert;

	 int otvet = graf[vert].size();
	 cout << "Кол-во смежных вершин: " << otvet;*/
	int x,y,w;
	map<int, list<pair<int, double>>>l_Adj;
	while (cin.peek() != EOF) {
		cin >> x >> y >> w; 
		if (!isWeigth) w = 1.0;
		auto it_x = l_Adj.find(x);
		bool fl = true;
		if (it_x != l_Adj.end()) {
			for (auto it_y = it_x->second.begin(); it_y != it_x->second.end(); it_y++)
				if (it_y->first == y) { 
				fl = false; 
				break;
			}
		}
		//if (orient) {
			if (fl) {
				l_Adj[x].push_back(make_pair(y, w));
				if (l_Adj.find(y) == l_Adj.end()) {
					l_Adj[y].push_back(make_pair(0, 0));
					auto it = l_Adj.find(y);
					it->second.erase(it->second.begin());
				}
			}
		//}
		/*else if (fl) {
			l_Adj[x].push_back(make_pair(y, w));
			l_Adj[y].push_back(make_pair(x, w));
		}*/
	}

	
	for (auto it = l_Adj.begin(); it != l_Adj.end(); it++) {
		cout << it->first << " : ";
		if (isWeigth) {
			for (auto it_1 = it->second.begin(); it_1 != it->second.end(); it_1++)
				cout << "{" << it_1->first << ", " << it_1->second << "};";
		}
		else {
			for (auto it_1 = it->second.begin(); it_1 != it->second.end(); it_1++)
				cout << it_1->first << "; ";
		}
		cout << endl;
	}


	return 0;
}