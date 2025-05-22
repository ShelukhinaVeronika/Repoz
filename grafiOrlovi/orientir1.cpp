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
            if (l_Adj.find(y) == l_Adj.end()) {
                l_Adj[y].push_back(make_pair(0, 0));
                auto it = l_Adj.find(y);
                it->second.erase(it->second.begin());
            }
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
    int vertex;
    cout << "Введите вершину для поиска смежных: ";
    cin >> vertex;

    auto it = l_Adj.find(vertex);
    if (it != l_Adj.end()) {
        cout << "Смежные вершины: ";
        for (auto& neighbor : it->second) {
            cout << neighbor.first << " ";
        }
        cout << endl << "Количество смежных вершин: " << it->second.size() << endl;
    }
    else {
        cout << "Вершина не найдена" << endl;
    }

    return 0;
}