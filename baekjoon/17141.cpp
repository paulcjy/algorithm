#include <bits/stdc++.h>
using namespace std;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, ans = INT_MAX;
int arr[52][52];
int p[12];
vector<pi2> place;

int bfs(vector<pi2> &virus) {
    int vis[52][52];
    memset(vis, -1, sizeof(vis));
    queue<pi2> q;
    for (auto [x, y] : virus) {
        q.push({x, y});
        vis[x][y] = 0;
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (vis[nx][ny] != -1 || arr[nx][ny]) continue;
            q.push({nx, ny});
            vis[nx][ny] = vis[x][y] + 1;
        }
    }
    int t = -1;
    int emp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] > t) t = vis[i][j];
            if (vis[i][j] == -1 && arr[i][j] == 0) emp++;
        }
    }
    if (emp > 0) return -1;
    return t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                place.push_back({i, j});
                arr[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < place.size(); i++)
        p[i] = i >= m;
    do {
        vector<pi2> virus;
        for (int i = 0; i < place.size(); i++)
            if (p[i] == 0) virus.push_back(place[i]);
        int t = bfs(virus);
        if (t != -1) ans = min(ans, t);
    } while (next_permutation(p, p+place.size()));
    cout << (ans == INT_MAX ? -1 : ans);
}