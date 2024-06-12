#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int arr[101][101];
int mp[101][101];
int vis[101][101];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j];
    
    int island = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mp[i][j] || arr[i][j] == 0) continue;
            queue<pair<int, int>> q;
            q.push({i, j});
            mp[i][j] = island;
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = cur.X + dx[d];
                    int ny = cur.Y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (mp[nx][ny] || arr[nx][ny] == 0) continue;
                    q.push({nx, ny});
                    mp[nx][ny] = island;
                }
            }
            island++;
        }
    }

    int ans = 100000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mp[i][j] == 0) continue;
            island = mp[i][j];
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = cur.X + dx[d];
                    int ny = cur.Y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (mp[nx][ny] == island) continue;
                    if (mp[nx][ny]) {
                        ans = min(ans, vis[cur.X][cur.Y]);
                        continue;
                    }
                    int nextDist = vis[cur.X][cur.Y] + 1;
                    if (vis[nx][ny] == 0 || vis[nx][ny] > nextDist) {
                        vis[nx][ny] = nextDist;
                        q.push({nx, ny});
                    }
                }
            }
            island++;
        }
    }
    cout << ans;
    return 0;
}