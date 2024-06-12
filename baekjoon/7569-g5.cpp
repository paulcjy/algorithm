#include <bits/stdc++.h>

using namespace std;

int box[101][101][101];
int day[101][101][101];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, h;
    cin >> m >> n >> h;

    vector<tuple<int, int, int>> v;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1)
                    v.push_back({i, j, k});
                if (box[i][j][k] == -1)
                    day[i][j][k] = -1;
            }
        }
    }

    queue<tuple<int, int, int>> q;
    for (tuple<int, int, int> t : v) {
        q.push(t);
        int x, y, z;
        tie(x, y, z) = t;
        day[x][y][z] = 1;
    }
    while(!q.empty()) {
        tuple<int, int, int> cur = q.front();
        q.pop();
        int x, y, z;
        tie(x, y, z) = cur;
        for (int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
            if (day[nx][ny][nz] > 0 || box[nx][ny][nz] == -1)continue;
            q.push({nx, ny, nz});
            day[nx][ny][nz] = day[x][y][z] + 1;
        }
    }

    int maxDay = 0, isImpossible = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < h; k++) {
                if (day[i][j][k] == 0) {
                    isImpossible = 1;
                    break;
                }
                if (day[i][j][k] > maxDay)
                    maxDay = day[i][j][k];
            }
        }
    }
    if (isImpossible)
        cout << -1;
    else
        cout << maxDay - 1;
    return 0;
}