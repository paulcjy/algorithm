#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int arr[301][301];
int vis[301][301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int l;
        pair<int, int> start, dest;
        cin >> l >> start.X >> start.Y >> dest.X >> dest.Y;

        memset(vis, -1, sizeof(vis));

        queue<pair<int, int>> q;
        q.push(start);
        vis[start.X][start.Y] = 0;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            if (cur == dest) {
                cout << vis[cur.X][cur.Y] << '\n';
                break;
            }
            for (int d = 0; d < 8; d++) {
                int nx = cur.X + dx[d];
                int ny = cur.Y + dy[d];
                if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
                if (vis[nx][ny] != -1) continue;
                q.push({nx, ny});
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            }
        }
    }

    return 0;
}