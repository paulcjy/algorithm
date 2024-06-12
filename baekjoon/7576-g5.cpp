#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int box[1001][1001];
int day[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1)
                v.push_back({i, j});
            if (box[i][j] == -1)
                day[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    for (pair<int, int> c : v) {
        q.push(c);
        day[c.X][c.Y] = 1;
    }
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (day[nx][ny] > 0 || box[nx][ny] == -1) continue;
            q.push({nx, ny});
            day[nx][ny] = day[cur.X][cur.Y] + 1;
        }
    }

    int maxDay = 0, isImpossible = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (day[i][j] == 0) {
                isImpossible = 1;
                break;
            }
            if (day[i][j] > maxDay)
                maxDay = day[i][j];
        }
    }

    if (isImpossible)
        cout << -1;
    else
        cout << maxDay - 1;

    return 0;
}