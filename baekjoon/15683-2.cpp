// back tracking
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int U = 0b1000;
int R = 0b0100;
int D = 0b0010;
int L = 0b0001;
int dirs[4] = {U, R, D, L};
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
vector<pair<int, int>> cctvs;
vector<pair<int, int>> walls;

void upd(int x, int y, int dir) {
    while (1) {
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] == -1) return;
        vis[x][y] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (0 < board[i][j] && board[i][j] < 6)
                cctvs.push_back({i, j});
            else if (board[i][j] == 6)
                walls.push_back({i, j});
        }
    }
    for (int tmp = 0; tmp < (1 << (2 * cctvs.size())); tmp++) {
        int brute = tmp;
        memset(vis, 0, sizeof(vis));
        for (auto wall : walls)
            vis[wall.X][wall.Y] = -1;
        for (auto cctv : cctvs) {
            int dir = brute % 4;
            brute /= 4;
            auto [x, y] = cctv;
            vis[x][y] = 1;
            int cctvNum = board[x][y];
            int cctvType = cctvTypes[cctvNum][dir];
            for (int d : dirs)
                if (cctvType & d)
                    upd(x, y, d);
        }
        int val = 0;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                val += (vis[i][j] == 0);
        ans = min(ans, val);
    }
    cout << ans;
}