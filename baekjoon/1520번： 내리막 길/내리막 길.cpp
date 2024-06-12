#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, m;
int a[505][505];
int d[505][505];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    if (x == n-1 && y == m-1) return;
    d[x][y] = 0;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (a[x][y] <= a[nx][ny]) continue;
        if (d[nx][ny] == -1) dfs(nx, ny);
        d[x][y] += d[nx][ny];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) cin >> a[i][j];
    
    memset(d, -1, sizeof(d));
    d[n-1][m-1] = 1;
    dfs(0, 0);
    cout << (d[0][0] == -1 ? 0 : d[0][0]);
}