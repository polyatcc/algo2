#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
queue<int> que;
vector<int> ans;
vector<int> d;
int n, m, a, b, f;


int main() {
    freopen("pathbge1.in", "r", stdin);
    freopen("pathbge1.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    graph.resize(n);
    d.resize(n);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; ++i) {
        d[i] = 1e+8;
    }
    que.push(0);
    d[0] = 0;
    while (!que.empty()) {
        f = que.front();
        que.pop();
        for(auto j : graph[f]) {
            if (d[j] == 1e+8){
                que.push(j);
                d[j] = d[f] + 1;
            }
        }
    }
    for (auto i : d) {
        cout << i << " ";

    }
    return 0;
}