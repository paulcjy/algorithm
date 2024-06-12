#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int arr[101][101];
int v1[101][101];
int v2[101][101];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans1 = 0, ans2 = 0;
    char input;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input;
            if (input == 'R')
                arr[i][j] = 1;
            else if (input == 'G')
                arr[i][j] = 2;
            else
                arr [i][j] = 0;
        }
    }
    
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v1[i][j]) continue;
            q.push({i, j});
            v1[i][j] = 1;
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (v1[nx][ny] || arr[cur.X][cur.Y] != arr[nx][ny]) continue;
                    q.push({nx, ny});
                    v1[nx][ny] = 1;
                }
            }
            ans1++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v2[i][j]) continue;
            q.push({i, j});
            v2[i][j] = 1;
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (v2[nx][ny] || (!arr[cur.X][cur.Y] != !arr[nx][ny])) continue;
                    q.push({nx, ny});
                    v2[nx][ny] = 1;
                }
            }
            ans2++;
        }
    }
    cout << ans1 << ' ' << ans2;

    return 0;
}