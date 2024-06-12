#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int arr[1001][1001];
int fire[1001][1001];
int man[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int w, h, escape = 0;
        char input;
        cin >> w >> h;

        memset(arr, 0, sizeof(arr));
        memset(fire, -1, sizeof(fire));
        memset(man, -1, sizeof(man));
        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> input;
                if (input == '#') continue;
                arr[i][j] = 1;
                if (input == '@') {
                    q1.push({i, j});
                    man[i][j] = 0;
                }
                if (input == '*') {
                    q2.push({i, j});
                    fire[i][j] = 0;
                }
            }
        }

        while (!q2.empty()) {
            auto cur = q2.front(); q2.pop();
            for (int d = 0; d < 4; d++) {
                int nx = cur.X + dx[d];
                int ny = cur.Y + dy[d];
                if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                if (fire[nx][ny] >= 0 || arr[nx][ny] == 0) continue;
                q2.push({nx, ny});
                fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            }
        }

        while (!q1.empty() && !escape) {
            auto cur = q1.front(); q1.pop();
            for (int d = 0; d < 4; d++) {
                int nx = cur.X + dx[d];
                int ny = cur.Y + dy[d];
                if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
                    cout << man[cur.X][cur.Y] + 1 << '\n';
                    escape = 1;
                    break;
                }
                if (man[nx][ny] >= 0 || arr[nx][ny] == 0) continue;
                if (fire[nx][ny] <= man[cur.X][cur.Y]+1 && fire[nx][ny] != -1) continue;
                q1.push({nx, ny});
                man[nx][ny] = man[cur.X][cur.Y] + 1;
            }
        }
        if (escape) continue;
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}