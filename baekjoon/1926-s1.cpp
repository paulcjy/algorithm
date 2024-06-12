#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int board[501][501];
int vis[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, picCount = 0, maxArea = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            if (board[i][j] == 0) continue;

            picCount++;
            int area = 0;
            queue<pair<int, int>> q;
            q.push({i, j});
            vis[i][j] = 1;
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                area++;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || board[nx][ny] != 1) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            maxArea = max(maxArea, area);
        }
    }

    cout << picCount << '\n' << maxArea;

    return 0;
}