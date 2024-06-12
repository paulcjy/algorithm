#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char arr[5][5];
int vis[5][5];
int p[25];
int ans = 0;

bool bfs() {
    memset(vis, 0, sizeof(vis));
    int cnt = 0, S = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < 25; i++) {
        if (p[i] == 0) {
            q.push({i / 5, i % 5});
            vis[i/5][i%5] = 1;
            break;
        }
    }
    while (!q.empty()) {
        auto cur = q.front(); q.pop(); cnt++;
        if (arr[cur.X][cur.Y] == 'S') S++;
        for (int d = 0; d < 4; d++) {
            int nx = cur.X + dx[d];
            int ny = cur.Y + dy[d];
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if (vis[nx][ny] || p[5 * nx + ny]) continue;
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
    return (cnt == 7 && S >= 4) ? true : false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) 
        for (int j = 0; j < 5; j++) 
            cin >> arr[i][j];
    for (int i = 7; i < 25; i++)
        p[i] = 1;

    do {
        if (bfs()) ans++;
    } while (next_permutation(p, p+25));
    cout << ans;
}