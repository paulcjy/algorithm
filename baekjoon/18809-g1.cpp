#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int arr[52][52];
pair<int, int> vis[52][52];
int n, m, g, r, total;
int ans = 0, cnt = 0;
vector<pair<int, int>> v;
int perm[10];
int p[10];
bool isUsed[10];

void bt(int k) {
    if (k == total) {
        memset(vis, -1, sizeof(vis));
        cnt = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < total; i++) {
            int x, y;
            tie(x, y) = v[i];
            if (p[i] == 1) {
                vis[x][y] = {0, 1};
                q.push({x, y});
            }
            else if (p[i] == 2) {
                vis[x][y] = {0, 2};
                q.push({x, y});
            }
        }
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int curTime, curColor;
            tie(curTime, curColor) = vis[cur.X][cur.Y];
            if (curColor == 3) continue;
            for (int d = 0; d < 4; d++) {
                int nx = cur.X + dx[d];
                int ny = cur.Y + dy[d];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (arr[nx][ny] == 0) continue;
                int nextTime, nextColor;
                tie(nextTime, nextColor) = vis[nx][ny];
                if (nextTime == -1 && nextColor == -1) {
                    vis[nx][ny] = {curTime + 1, curColor};
                    q.push({nx, ny});
                }
                else {
                    if (curColor == nextColor || nextColor == 3) continue;
                    if (nextTime == curTime + 1) {
                        vis[nx][ny] = {nextTime, 3};
                        cnt++;
                    }
                }
            }
        }
        ans = max(ans, cnt);
        return;
    }
    int prev = -1;
    for (int i = 0; i < total; i++) {
        if (!isUsed[i] && prev != perm[i]) {
            p[k] = perm[i];
            isUsed[i] = 1;
            prev = perm[i];
            bt(k+1);
            isUsed[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> g >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
                v.push_back({i, j});
        }
    }
    total = v.size();
    fill_n(perm, g, 1);
    fill_n(perm+g, r, 2);
    sort(perm, perm+total);
    bt(0);
    cout << ans;
}