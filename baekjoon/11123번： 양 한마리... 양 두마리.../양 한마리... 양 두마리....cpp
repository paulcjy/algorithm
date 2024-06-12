#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int t, h, w;
char a[105][105];
int v[105][105];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> h >> w;
        for (int i = 0; i < h; i++) 
            for (int j = 0; j < w; j++) 
                cin >> a[i][j];
        memset(v, 0, sizeof(v));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (a[i][j] == '.' || v[i][j]) continue;
                ans++;
                queue<pi2> q;
                q.push({i, j});
                v[i][j] = 1;
                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                        if (a[nx][ny] == '.' || v[nx][ny]) continue;
                        q.push({nx, ny});
                        v[nx][ny] = 1;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}