#include <bits/stdc++.h>
using namespace std;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;
#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, ans;
int arr[10][10];
int p[70];
vector<pi2> v;
vector<pi2> virus;

int bfs() {
    int run[10][10];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            run[i][j] = arr[i][j];
    queue<pi2> q;
    for (auto v : virus) q.push(v);
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (run[nx][ny] != 0) continue;
            q.push({nx, ny});
            run[nx][ny] = 2;
        }
    }
    int safe = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (run[i][j] == 0) safe++;
    return safe;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) v.push_back({i, j});
            else if (arr[i][j] == 2) virus.push_back({i, j});
        }
    }
    for (int i = 0; i < v.size(); i++)
        p[i] = i > 2;
    do {
        vector<pi2> wall;
        for (int i = 0; i < v.size(); i++)
            if (p[i] == 0) wall.push_back(v[i]);
        for (auto [x, y] : wall) arr[x][y] = 1;
        ans = max(ans, bfs());
        for (auto [x, y]: wall) arr[x][y] = 0;
    } while (next_permutation(p, p+v.size()));
    cout << ans;
}