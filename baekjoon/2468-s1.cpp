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

    int n, maxH = 0, minH = 100;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > maxH) maxH = arr[i][j];
            if (arr[i][j] < minH) minH = arr[i][j];
        }
    }

    int maxArea = 0;
    queue<pair<int, int>> q;
    for (int rain = minH - 1; rain <= maxH; rain++) {
        memset(vis, 0, sizeof(vis));
        int area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] || arr[i][j] <= rain) continue;
                q.push({i, j});
                vis[i][j] = 1;
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    for (int d = 0; d < 4; d++) {
                        int nx = cur.X + dx[d];
                        int ny = cur.Y + dy[d];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if (vis[nx][ny] || arr[nx][ny] <= rain) continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
                area++;
            }
        }
        if (area > maxArea) maxArea = area;
    }

    cout << maxArea;

    return 0;
}