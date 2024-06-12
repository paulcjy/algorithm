#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int arr[31][31][31];
int vis[31][31][31];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        int l, r, c, escape = 0;
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0) break;
        
        memset(arr, 0, sizeof(arr));
        memset(vis, -1, sizeof(vis));

        tuple<int, int, int> S, E;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    char input;
                    cin >> input;
                    if (input == '#') continue;
                    arr[i][j][k] = 1;
                    if (input == 'S')
                        S = {i, j, k};
                    if (input == 'E')
                        E = {i, j, k};
                }
            }
        }

        
        queue<tuple<int, int, int>> q;
        q.push(S);
        vis[get<0>(S)][get<1>(S)][get<2>(S)] = 0;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int x, y, z;
            tie(x, y, z) = cur;
            if (cur == E) {
                cout << "Escaped in " << vis[x][y][z] << " minute(s).\n";
                escape = 1;
                break;
            }
            for (int d = 0; d < 6; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                int nz = z + dz[d];
                if (nx < 0 || ny < 0 || nz < 0 || nx >= l || ny >= r || nz >= c) continue;
                if (vis[nx][ny][nz] >= 0 || arr[nx][ny][nz] == 0) continue;
                q.push({nx, ny, nz});
                vis[nx][ny][nz] = vis[x][y][z] + 1;
            }
        }
        if (!escape)
            cout << "Trapped!\n";
    }
    return 0;
}