// back tracking
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int U = 0b1000;
int R = 0b0100;
int D = 0b0010;
int L = 0b0001;
int dir[4] = {U, R, D, L};
int dx[9] = {0, 0, 1, 0, 0, 0, 0, 0, -1};
int dy[9] = {0, -1, 0, 0, 1, 0, 0, 0, 0};

int cctvTypes[6][4] = {
    {},
    {U, R, D, L},
    {U|D, R|L},
    {U|R, R|D, D|L, L|U},
    {U|R|D, U|R|L, U|D|L, R|D|L},
    {U|R|D|L}
};

int board[10][10];
int vis[10][10];
int n, m;
int ans = 65;
vector<tuple<int, int, int>> cctv;
vector<pair<int, int>> walls;

void bt(int k) {
    if (k == cctv.size()) {
        int cnt = 0;
        memset(vis, 0, sizeof(vis));
        for (auto wall : walls)
            vis[wall.X][wall.Y] = -1;
        for (auto cctv : cctv) {
            int x, y, t, nx, ny;
            tie(x, y, t) = cctv;
            vis[x][y] = 1;
            for (int d : dir) {
                if (t & d) {
                    nx = x; ny = y;
                    while (1) {
                        nx += dx[d];
                        ny += dy[d];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
                        if (vis[nx][ny] == -1) break;
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if (vis[i][j] == 0) cnt++;
        ans = min(ans, cnt);
        return;
    }
    int x, y, t, cctvNum;
    tie(x, y, t) = cctv[k];
    cctvNum = board[x][y];
    for (int i = 0; i < 4; i++) {
        t = cctvTypes[cctvNum][i];
        if (t) {
            cctv[k] = {x, y, t};
            bt(k+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (0 < board[i][j] && board[i][j] < 6)
                cctv.push_back({i, j, 0});
            else if (board[i][j] == 6)
                walls.push_back({i, j});
        }
    bt(0);
    cout << ans;
}