#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
int n, m, a, b;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n; ++i) {
        graph[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    int check = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i == j) && (graph[i][j] != 0)) {
                check = 0;
                break;
            }
            if (graph[i][j] != graph[j][i]) {
                check = 0;
                break;
            }
        }
    }
    if (check == 0) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    return 0;
}