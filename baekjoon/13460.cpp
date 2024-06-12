#include <bits/stdc++.h>
using namespace std;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[12][12];
int dist[12][12][12][12];
int n, m;
pair<int, int> R, B;
int ans = INT_MAX;

int bfs() {
    queue<tuple<int, int, int, int>> q;
    q.push({R.X, R.Y, B.X, B.Y});
    dist[R.X][R.Y][B.X][B.Y] = 0;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        auto [rx, ry, bx, by] = cur;
        int moved = dist[rx][ry][bx][by];
        if (moved == 10) return -1;
        for (int d = 0; d < 4; d++) {
            auto [nrx, nry, nbx, nby] = cur;
            while (arr[nbx+dx[d]][nby+dy[d]] == 1) {
                nbx += dx[d];
                nby += dy[d];
            }
            if (arr[nbx+dx[d]][nby+dy[d]] == -1) continue;
            while (arr[nrx+dx[d]][nry+dy[d]] == 1) {
                nrx += dx[d];
                nry += dy[d];
            }
            if (arr[nrx+dx[d]][nry+dy[d]] == -1) return moved+1;
            if (nrx == nbx && nry == nby) {
                if (d == 0) rx > bx ? nrx++ : nbx++;
                else if (d == 1) ry > by ? nby-- : nry--;
                else if (d == 2) rx > bx ? nbx-- : nrx--;
                else ry > by ? nry++ : nby++;
            }
            if (dist[nrx][nry][nbx][nby] != -1) continue;
            dist[nrx][nry][nbx][nby] = moved + 1;
            q.push({nrx, nry, nbx, nby});
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dist, -1, sizeof(dist));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char input;
            cin >> input;
            if (input == '#') arr[i][j] = 0;
            else if (input == 'O') arr[i][j] = -1;
            else {
                if (input == 'R') R = {i, j};
                if (input == 'B') B = {i, j};
                arr[i][j] = 1;
            }
        }
    }
    cout << bfs();
}