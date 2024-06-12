#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int arr[1001][1001];
int vis[1001][1001][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char input;
            cin >> input;
            arr[i][j] = input - '0';
        }
    }

    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    vis[0][0][0] = 1;
    while (!q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = q.front(); q.pop();
        if (x == n-1 && y == m-1) {
            cout << vis[x][y][broken];
            return 0;
        }
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            // 이동할 수 있고, 방문한 적이 없을 때
            if (arr[nx][ny] == 0 && vis[nx][ny][broken] == 0) {
                q.push({nx, ny, broken});
                vis[nx][ny][broken] = vis[x][y][broken] + 1;
            }
            // 아직 벽을 깨지 않았고, 벽이 있으며, 방문한 적이 없을 때
            if (!broken && arr[nx][ny] == 1 && vis[nx][ny][1] == 0) {
                q.push({nx, ny, 1});
                vis[nx][ny][1] = vis[x][y][broken] + 1;
            }
        }
    }
    cout << -1;
    return 0;
}