#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int input[5][5][5];
int maze[5][5][5];
int vis[5][5][5];
int plate[5];
int isUsed[5];
int dir[5] = {0};
int MAX = 0x7fffffff;
int ans = MAX;

void copyPlate(int (&maze)[5][5], int (&input)[5][5], int dir) {
    while (dir--) {
        int tmp[5][5];
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                tmp[j][4-i] = input[i][j];
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                input[i][j] = tmp[i][j];
    }
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            maze[i][j] = input[i][j];
}

int bfs(tuple<int, int, int> start) {
    auto [sx, sy, sz] = start;
    int ex = 4 - sx, ey = 4 - sy, ez = 4 - sz;
    if (maze[sx][sy][sz] == 0 || maze[ex][ey][ez] == 0) return -1;
    memset(vis, -1, sizeof(vis));
    queue<tuple<int, int, int>> q;
    q.push(start);
    vis[sx][sy][sz] = 0;
    while (!q.empty()) {
        auto [x, y, z] = q.front(); q.pop();
        for (int d = 0; d < 6; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            int nz = z + dz[d];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5) continue;
            if (vis[nx][ny][nz] != -1 || maze[nx][ny][nz] == 0) continue;
            q.push({nx, ny, nz});
            vis[nx][ny][nz] = vis[x][y][z] + 1;
        }
    }
    return vis[ex][ey][ez];
}

void bt(int k) {
    if (k == 10) {
        for (int i = 0; i < 5; i++)
            copyPlate(maze[i], input[plate[i]], dir[i]);
        tuple<int, int, int> start[4] = {{0, 0, 0}, {0, 0, 4}, {0, 4, 0}, {0, 4, 4}};
        for (auto s : start) {
            int result = bfs(s);
            if (result != -1) ans = min(ans, result);
        }
        return;
    }
    if (k < 5) {
        for (int i = 0; i < 5; i++) {
            if (isUsed[i]) continue;
            plate[k] = i;
            isUsed[i] = 1;
            bt(k+1);
            isUsed[i] = 0;
        }
    }
    else {
        for (int i = 0; i < 4; i++) {
            dir[k-5] = i;
            bt(k+1);
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                cin >> input[i][j][k];
    bt(0);
    if (ans == MAX) ans = -1;
    cout << ans;
}