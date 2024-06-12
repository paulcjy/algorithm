#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int arr[101][101];
int vis[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, k, cnt = 0;
    cin >> m >> n >> k;
    while (k--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        for (int i = a; i < x; i++)
            for (int j = b; j < y; j++)
                arr[i][j] = 1;
    }
    
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    queue<pair<int, int>> q;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1 || vis[i][j]) continue;
            int area = 0;
            q.push({i, j});
            vis[i][j] = 1;
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                area++;
                for (int d = 0; d < 4; d++) {
                    int nx = cur.X + dx[d];
                    int ny = cur.Y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (arr[nx][ny] || vis[nx][ny]) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            cnt++;
            v.push_back(area);
        }
    }
    cout << cnt << '\n';
    sort(v.begin(), v.end());
    for (auto area : v)
        cout << area << ' ';

    return 0;
}