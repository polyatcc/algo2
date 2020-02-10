#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> used;
int n, m, a, b;

void dfs(int now, int compnum) {
    used[now] = compnum;
    for (auto i : graph[now]) {
        if (used[i] == 0) {
            dfs(i, compnum);
        }
    }
}

int main() {
    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    graph.resize(n);
    used.resize(n);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    int compN = 1;
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            dfs(i, compN);
            ++compN;
        }
    }
    cout << compN - 1 << '\n';
    for (auto i : used) {
        cout << i << " ";
    }
    return 0;
}