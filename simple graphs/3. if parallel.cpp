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
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < n; ++i) {
        graph[i].resize(n);
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a - 1][b - 1]++;
    }
    int check = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if (i == j) {
                if (graph[i][j] > 1) {
                    check = 0;
                    break;
                }
            }
            if ((graph[i][j] + graph[j][i]) > 1) {
                check = 0;
                break;
            }
        }
    }
    if (check == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}