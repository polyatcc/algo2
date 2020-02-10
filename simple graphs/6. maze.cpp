#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
queue<pair<int, int>> que;
vector<pair<int, int>> maybe;
vector<vector<int>> d;
vector<vector<pair<int, int>>> pred;
vector<char> ans;
int n, m;
char a, b;
pair<int, int> f, k;


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    graph.resize(n);
    d.resize(n);
    pred.resize(n);
    for (int i = 0; i < n; ++i) {
        d[i].resize(m);
        pred[i].resize(m);
        graph[i].resize(m);
    }
    int startX, startY, finalX, finalY;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a;
            if (a == '.') {
                graph[i][j] = 1;
            } else if (a == '#') {
                graph[i][j] = 0;
            } else if (a == 'S') {
                startX = i;
                startY = j;
                graph[i][j] = 1;
            } else if (a == 'T') {
                finalX = i;
                finalY = j;
                graph[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            d[i][j] = 1e+8;
        }
    }
    que.push({startX, startY});
    d[startX][startY] = 0;
    while (!que.empty()) {
        f = que.front();
        maybe.emplace_back(f.first + 1, f.second);
        maybe.emplace_back(f.first - 1, f.second);
        maybe.emplace_back(f.first, f.second + 1);
        maybe.emplace_back(f.first, f.second - 1);
        que.pop();
        for(auto j : maybe) {
            if ((j.first >= 0) && (j.first <= n - 1)){
                if ((j.second >= 0) && (j.first <= n -1)) {
                    if (graph[j.first][j.second] == 1) {
                        if (d[j.first][j.second] == 1e+8) {
                            que.push(j);
                            pred[j.first][j.second] = f;
                            d[j.first][j.second] = d[f.first][f.second] + 1;
                        }
                    }
                }
            }
        }
        maybe.clear();
    }
    int check = 1;
    if (d[finalX][finalY] == 1e+8) {
        cout << -1 << '\n';
        check = 0;
    } else {
        cout << d[finalX][finalY] << '\n';
    }
    while ((finalX != startX) || (finalY != startY)) {
        k = pred[finalX][finalY];
        if (k.first < finalX) {
            ans.push_back('D');
        }
        if (k.first > finalX) {
            ans.push_back('U');
        }
        if (k.second < finalY) {
            ans.push_back('R');
        }
        if (k.second > finalY) {
            ans.push_back('L');
        }
        finalX = k.first;
        finalY = k.second;
    }
    reverse(ans.begin(), ans.end());
    if (check == 1) {
        for (auto i : ans) {
            cout << i;
        }
    }

    return 0;
}