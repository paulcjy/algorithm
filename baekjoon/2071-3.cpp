#include <bits/stdc++.h>
using namespace std;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

enum Direction { ROW, COL, UP, DOWN };
enum Status { UNKNOWN, O, X };

int n, n2;
int board[16][16];
int vis[16][16];
int s[4][32];
int e[4][32];
int dx[4] = {0, 1, -1, 1};
int dy[4] = {1, 0, 1, 1};
int bfsdx[4] = {1, -1, 0, 0};
int bfsdy[4] = {0, 0, 1, -1};

void getInput() {
    cin >> n;
    n2 = 2*n - 1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
            e[i][j] = n;
        }
    }
    for (int i = 2; i < 4; i++) {
        for (int j = 0; j < n2; j++) {
            cin >> s[i][j];
            e[i][j] = j < n ? j + 1 : n2 - j;
        }
    }
}

void setStone(int x, int y, int status) {
    e[ROW][x]--;
    e[COL][y]--;
    e[UP][x+y]--;
    e[DOWN][y-x+n-1]--;
    if (status == O) {
        s[ROW][x]--;
        s[COL][y]--;
        s[UP][x+y]--;
        s[DOWN][y-x+n-1]--;
    }
    board[x][y] = status;
}

bool canPutStone(int x, int y) {
    return e[ROW][x] > 0 && e[COL][y] > 0 && e[UP][x+y] > 0 && e[DOWN][y-x+n-1] > 0 && s[ROW][x] > 0 && s[COL][y] > 0 && s[UP][x+y] > 0 && s[DOWN][y-x+n-1] > 0;
}

void fillLine(int dir, int line, int status) {
    int len = n, x = 0, y = 0;
    if (dir == ROW) x = line;
    else if (dir == COL) y = line;
    else {
        if (line < n) {
            len = line + 1;
            x = line;
        }
        else {
            len = n2 - line;
            x = n - 1;
            y = line - n + 1;
        }
        if (dir == DOWN) x = n - 1 - x;
    }
    while (len--) {
        if (board[x][y] == UNKNOWN)
            setStone(x, y, status);
        x += dx[dir];
        y += dy[dir];
    }
}

bool putStones() {
    int cnt = 0;
    for (int dir = 0; dir < 4; dir++) {
        for (int line = 0; line < n2; line++) {
            if (dir < 2 && line >= n) break; // 행 열은 n이 끝
            if (e[dir][line] == 0) continue; // 다 채웠으면 패스
            if (s[dir][line] == 0) fillLine(dir, line, X), cnt++; // 놓을 돌이 0이면 빈칸은 전부 X로
            else if (s[dir][line] == e[dir][line]) fillLine(dir, line, O), cnt++; // 놓을 돌이 빈칸과 같으면 빈칸을 전부 O로
        }
    }
    return cnt != 0;
}

bool isCompleted() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == UNKNOWN)
                return false;
    return true;
}

void bfs() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == O)
                vis[i][j] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(i == 0 || i == n-1 || j == 0 || j == n-1) || vis[i][j]) continue;
            queue<pi2> q;
            q.push({i, j});
            vis[i][j]= 1;
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + bfsdx[d];
                    int ny = y + bfsdy[d];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny]) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
}

int countHouse() {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (vis[i][j] == 0)
                cnt++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    getInput();
    while (putStones()) {}
    if (!isCompleted()) {
        vector<pi2> v;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == UNKNOWN)
                    v.push_back({i, j});
        for (auto [x, y] : v) {
            if (canPutStone(x, y)) {
                setStone(x, y, O);
                while (putStones()) {}
            }
        }
    }
    bfs();
    cout << countHouse();
}