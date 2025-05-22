//2. Дан неориентированный граф. Вставить в граф ребро, соединяющее вершины A и B.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int n, x;
    cout << "Введите n: ";
    cin >> n;
    vector<vector <int>> graf(n);
    cout << "Введите матрицу смежности: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (x != 0) {
                graf[i].push_back(j);
            }
        }
    }
    int vert;
    cout << "Введите номер вершины: ";
    cin >> vert;

    int otvet = graf[vert].size();
    cout << "Кол-во смежных вершин: " << otvet;
    return 0;
}