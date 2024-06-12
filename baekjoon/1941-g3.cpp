#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool mask[5][5];
char arr[5][5];
bool vis[5][5];
int ans = 0;

void bt(int k, int start) {
    if (k == 7) {
        pair<int, int> first;
        int countNext = 0;
        int S = 0;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                if(mask[i][j]) {
                    first.X = i;
                    first.Y = j;
                    break;
                }
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> q;
        q.push(first);
        vis[first.X][first.Y] = 1;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            countNext++;
            if (arr[cur.X][cur.Y] == 'S') S++;
            for (int d = 0; d < 4; d++) {
                int nx = cur.X + dx[d];
                int ny = cur.Y + dy[d];
                if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                if (vis[nx][ny] || mask[nx][ny] == 0) continue;
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
        if (countNext == 7 && S >= 4) ans++;
        return;
    }
    for (int i = start; i < 19+k; i++) {
        mask[i/5][i%5] = 1;
        bt(k+1, i+1);
        mask[i/5][i%5] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) 
        for (int j = 0; j < 5; j++) 
            cin >> arr[i][j];
    bt(0, 0);
    cout << ans;
}