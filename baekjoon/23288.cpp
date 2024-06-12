#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int arr[22][22];
int score[22][22];
int dice[6];
int n, m, k;
int x = 0, y = 0, dir = 0, ans = 0;

void setDice() {
    for (int i = 0; i < 6; i++)
        dice[i] = i + 1;
}

void setScore() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (score[i][j]) continue;
            int vis[22][22] = {};
            int cnt = 0;
            queue<pair<int, int>> q;
            q.push({i, j});
            vis[i][j] = 1;
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop(); cnt++;
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (vis[nx][ny] || arr[x][y] != arr[nx][ny]) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            int s = arr[i][j] * cnt;
            for (int x = 0; x < n; x++)
                for (int y = 0; y < m; y++)
                    if (vis[x][y])
                        score[x][y] = s;
        }
    }
}

void switchDice() {
    int tmp = 0;
    switch (dir) {
        // 동
        case 0:
            tmp = dice[0];
            dice[0] = dice[3];
            dice[3] = dice[5];
            dice[5] = dice[2];
            dice[2] = tmp;
            break;
        // 남
        case 1:
            tmp = dice[0];
            dice[0] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[4];
            dice[4] = tmp;
            break;
        // 서
        case 2:
            tmp = dice[0];
            dice[0] = dice[2];
            dice[2] = dice[5];
            dice[5] = dice[3];
            dice[3] = tmp;
            break;
        // 북
        case 3:
            tmp = dice[0];
            dice[0] = dice[4];
            dice[4] = dice[5];
            dice[5] = dice[1];
            dice[1] = tmp;
    }
}

void moveDice(int k) {
    if (k == 0) return;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
        dir = (dir + 2) % 4;
        moveDice(k);
        return;
    }
    x += dx[dir];
    y += dy[dir];
    switchDice();
    ans += score[x][y];
    k--;
    if (dice[5] > arr[x][y]) {
        dir = (dir + 1) % 4;
        moveDice(k);
    }
    else if (dice[5] < arr[x][y]) {
        dir = (dir + 3) % 4;
        moveDice(k);
    }
    else moveDice(k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    setDice();
    setScore();
    moveDice(k);
    cout << ans;
}