#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int arr[22][22];
int dice[6];
int n, m, x, y, k;

void moveDice(int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < 0 || ny < 0 || nx >= n || ny >= m) return;
    x += dx[dir];
    y += dy[dir];
    int tmp;
    switch (dir) {
        case 0:
            tmp = dice[0];
            dice[0] = dice[3];
            dice[3] = dice[5];
            dice[5] = dice[2];
            dice[2] = tmp;
            break;
        case 1:
            tmp = dice[0];
            dice[0] = dice[2];
            dice[2] = dice[5];
            dice[5] = dice[3];
            dice[3] = tmp;
            break;
        case 2:
            tmp = dice[0];
            dice[0] = dice[4];
            dice[4] = dice[5];
            dice[5] = dice[1];
            dice[1] = tmp;
            break;
        case 3:
            tmp = dice[0];
            dice[0] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[4];
            dice[4] = tmp;
    }
    if (arr[x][y] == 0) arr[x][y] = dice[5];
    else {
        dice[5] = arr[x][y];
        arr[x][y] = 0;
    }
    cout << dice[0] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    while (k--) {
        int dir;
        cin >> dir;
        moveDice(dir-1);
    }
}