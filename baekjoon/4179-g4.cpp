#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int arr[1001][1001];
int fire[1001][1001];
int run[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    char input;
    cin >> r >> c;

    pair<int, int> jihun;
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> input;
            if (input == '#') continue;
            arr[i][j] = 1;
            if (input == 'F') {
                q.push({i, j});
                fire[i][j] = 1;
            }
            else if (input == 'J') {
                jihun.X = i;
                jihun.Y = j;
                run[i][j] = 1;
            }
        }
    }
    
    // fire bfs
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (fire[nx][ny] > 0 || arr[nx][ny] == 0) continue;
            q.push({nx, ny});
            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
        }
    }
    
    // Jihun bfs
    q.push(jihun);
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
                cout << run[cur.X][cur.Y];
                return 0;
            };
            if (run[nx][ny] > 0 || arr[nx][ny] == 0) continue;
            if (fire[nx][ny] != 0 && run[cur.X][cur.Y]+1 >= fire[nx][ny]) continue;
            q.push({nx, ny});
            run[nx][ny] = run[cur.X][cur.Y] + 1;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}