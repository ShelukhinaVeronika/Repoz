//2. ��� ����������������� ����. �������� � ���� �����, ����������� ������� A � B.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int n, x;
    cout << "������� n: ";
    cin >> n;
    vector<vector <int>> graf(n);
    cout << "������� ������� ���������: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (x != 0) {
                graf[i].push_back(j);
            }
        }
    }
    int vert;
    cout << "������� ����� �������: ";
    cin >> vert;

    int otvet = graf[vert].size();
    cout << "���-�� ������� ������: " << otvet;
    return 0;
}