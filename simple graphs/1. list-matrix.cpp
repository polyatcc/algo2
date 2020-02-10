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
        graph[a - 1][b - 1] = 1;
    }
    for (int i = 0; i < n; ++i){
        for (auto j : graph[i]) {
            cout << j << " ";
        }
        cout << '\n';
    }

    return 0;
}