#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int arr[301][301];
int vis[301][301];
int sea[301][301];
int n, m, year;

void printArr() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

void checkSea() {
    memset(sea, 0, sizeof(sea));
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < m-1; j++) {
            if (arr[i][j] == 0) continue;
            for (int d = 0; d < 4; d++) {
                int x = i + dx[d];
                int y = j + dy[d];
                if (arr[x][y] == 0) sea[i][j]++;
            }
        }
    }
}

void melt() {
    checkSea();
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < m-1; j++) {
            arr[i][j] -= sea[i][j];
            if (arr[i][j] < 0) arr[i][j] = 0;
        }
    }
}

bool isZero() {
    int ice = 0;
    for (int i = 1; i < n-1; i++) 
        for (int j = 1; j < m-1; j++) 
            if (arr[i][j] != 0) ice++;
    return !ice;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> arr[i][j];
    
    
    while (1) {
        year++;
        melt();

        if (isZero()) {
            cout << 0;
            return 0;
        }

        int cnt = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                if (vis[i][j] || arr[i][j] == 0) continue;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    for (int d = 0; d < 4; d++) {
                        int nx = cur.X + dx[d];
                        int ny = cur.Y + dy[d];
                        if (nx < 0 || ny < 0 || nx >= n-1 || ny >= m-1) continue;
                        if (vis[nx][ny] || arr[nx][ny] == 0) continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
                cnt++;
            }
        }

        if (cnt >= 2) {
            cout << year;
            return 0;
        }
    }
}