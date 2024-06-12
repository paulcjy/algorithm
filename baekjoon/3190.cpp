#include <bits/stdc++.h>
using namespace std;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int board[102][102];
int n, k, dir = 1, t = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pi2> snake;
queue<pi2> turn;

bool go(int k) {
    while (k--) {
        t++;
        auto [x, y] = snake.back();
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] == 1) return false;
        if (board[nx][ny] == 0) {
            auto [bx, by] = snake.front(); snake.pop();
            board[bx][by] = 0;
        }
        snake.push({nx, ny});
        board[nx][ny] = 1;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    while (k--) {
        int r, c;
        cin >> r >> c;
        board[r-1][c-1] = 2;
    }
    cin >> k;
    while (k--) {
        int time;
        char dir;
        cin >> time >> dir;
        turn.push({time, (dir == 'L') ? -1 : 1});
    }
    
    snake.push({0, 0});
    board[0][0] = 1;
    while (!turn.empty()) {
        auto [tt, d] = turn.front(); turn.pop();
        bool alive = go(tt-t);
        if (!alive) {
            cout << t;
            return 0;
        }
        dir = (dir + 4 + d) % 4;
    } 
    go(110);
    cout << t;
}