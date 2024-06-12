#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int arr[51][51];
int vis[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x, y, ans = 0;
        cin >> m >> n >> k;
        memset(arr, 0, sizeof(arr));
        memset(vis, 0, sizeof(vis));
        
        while (k--) {
            cin >> y >> x;
            arr[x][y] = 1;
        }
        
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 0 || vis[i][j]) continue;
                q.push({i, j});
                vis[i][j] = 1;
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (vis[nx][ny] || arr[nx][ny] == 0) continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}