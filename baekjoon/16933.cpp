#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int arr[1001][1001];
int vis[1001][1001][12];
int n, m, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char input;
            cin >> input;
            arr[i][j] = input - '0';
        }
    }

    queue<tuple<int, int, int>> q;
    bool day = 1;
    q.push({0, 0, k});
    vis[0][0][k] = 1;
    while (!q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (arr[nx][ny] == 0 && vis[nx][ny][broken] == 0) {
                q.push({nx, ny, broken});
                vis[nx][ny][broken] = vis[x][y][broken] + 1;
            }
            if (broken > 0 && arr[nx][ny] == 1 && vis[nx][ny][broken-1] == 0 && day) {
                q.push({nx, ny, broken - 1});
                vis[nx][ny][broken-1] = vis[x][y][broken] + 1;
            }
        }
        if (!day && vis[x][y][11] != -1) {
            q.push({x, y, broken});
            vis[x][y][broken]++;
            vis[x][y][11] = -1;
        }
        day = !day;
    }
    int mx = 0x7fffffff;
    int ans = mx;
    for (int dist : vis[n-1][m-1])
        if (dist > 0) ans = min(ans, dist);
    
    if (ans == mx)
        cout << -1;
    else
        cout << ans;
    return 0;
}