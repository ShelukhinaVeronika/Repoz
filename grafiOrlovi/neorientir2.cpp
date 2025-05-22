//2. Дан неориентированный граф. Вставить в граф ребро, соединяющее вершины A и B.
#include <iostream>
#include <map>
#include <list>
using namespace std;

bool isWeigth(int w) {
    if (w != 1) return 1;
    else return 0;
}

int main() {
    setlocale(LC_ALL, "RU");
    int x, y, w, n;
    map<int, list<pair<int, double>>> l_Adj;
    cout << "Введите количество вершин графа: ";
    cin >> n;
    cout << "Введите " << n << " рёбер в формате 'исходная_вершина конечная_вершина вес':" << endl;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (cin.peek() == ' ') {
            cin >> w;
        }
        else {
            w = 1;
        }
        auto it_x = l_Adj.find(x);
        bool fl = true;
        if (it_x != l_Adj.end()) {
            for (auto it_y = it_x->second.begin(); it_y != it_x->second.end(); it_y++)
                if (it_y->first == y) {
                    fl = false;
                    break;
                }
        }
        if (fl) {
            l_Adj[x].push_back(make_pair(y, w));
            l_Adj[y].push_back(make_pair(x, w));
        }
    }

    for (auto it = l_Adj.begin(); it != l_Adj.end(); it++) {
        cout << it->first << " : ";
        if (isWeigth(1)) {
            for (auto it_1 = it->second.begin(); it_1 != it->second.end(); it_1++)
                cout << "{" << it_1->first << ", " << it_1->second << "};";
        }
        else {
            for (auto it_1 = it->second.begin(); it_1 != it->second.end(); it_1++)
                cout << it_1->first << "; ";
        }
        cout << endl;
    }
}