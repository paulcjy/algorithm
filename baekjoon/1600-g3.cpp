#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[12] = {1, -1, 0, 0, 1, 2, 2, 1, -1, -2, -2, -1};
int dy[12] = {0, 0, 1, -1, 2, 1, -1, -2, -2, -1, 1, 2};
int k, w, h;
int arr[201][201];
int vis[201][201][31];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> w >> h;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) 
            cin >> arr[i][j];

    queue<tuple<int, int, int>> q;
    q.push({0, 0, k});
    vis[0][0][k] = 1;
    while (!q.empty()) {
        int x, y, horse;
        tie(x, y, horse) = q.front(); q.pop();
        for (int d = 0; d < 12; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if (arr[nx][ny]) continue;
            if (d < 4) {
                if (vis[nx][ny][horse]) continue;
                q.push({nx, ny, horse});
                vis[nx][ny][horse] = vis[x][y][horse] + 1;
            }
            else {
                if (!horse || vis[nx][ny][horse-1]) continue;
                q.push({nx, ny, horse - 1});
                vis[nx][ny][horse-1] = vis[x][y][horse] + 1;
            }
        }
    }
    int mx = 0x7fffffff;
    int ans = mx;
    for (int cnt : vis[h-1][w-1])
        if (cnt) ans = min(ans, cnt);
    if (ans == mx)
        cout << -1;
    else
        cout << ans - 1;
    return 0;
}