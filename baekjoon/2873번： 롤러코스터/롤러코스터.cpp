#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;
#define X first
#define Y second

int r, c, x, y;
int a[1010][1010];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
char chdir[4] = {'R', 'D', 'U', 'L'};
char nextline[4] = {'D', 'R', 'R', 'D'};

bool oob(int a, int b) { return a < 0 || a >= r || b < 0 || b >= c; }

void run(int n, bool isDown = true) {
    int d = isDown ? (y == 0 ? 0 : 3) : (x == 0 ? 1 : 2);
    while (n--) {
        for (int nx = x + dx[d], ny = y + dy[d]; !oob(nx, ny); nx += dx[d], ny += dy[d]) {
            cout << chdir[d];
            x = nx; y = ny;
        }
        if (x == r-1 && y == c-1) break;
        cout << nextline[d];
        isDown ? x++ : y++;
        if (x == r-1 && y == c-1) break;
        d = 3 - d;
    }
}

pi2 getMin() {
    int m = 10000;
    pi2 ret;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!((i+j)&1)) continue;
            if (a[i][j] < m) {
                m = a[i][j];
                ret = {i, j};
            }
        }
    }
    return ret;
}

void avoid(int px, int py) {
    int startRow = x;
    bool hor = false;
    int dest = y == 0 ? c - 1  : 0;
    int lr = y == 0 ? 0 : 3;
    int ud = 1;
    while (y != dest) {
        int &dir = hor ? lr : ud;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx == px && ny == py) { hor = !hor; continue; }
        cout << chdir[dir];
        x = nx; y = ny;
        if (!hor) dir = 3 - dir;
        hor = !hor;
    }
    if (x == r-1 && y == c-1) return;
    if (x == startRow) { cout << 'D'; x++; }
    if (x == r-1 && y == c-1) return;
    cout << 'D'; x++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) cin >> a[i][j];

    if (r & 1) run(-1);
    else if (c & 1) run(-1, 0);
    else {
        auto [px, py] = getMin();
        int target = px < 2 ? 0 : (px > r-3 ? r-2 : px);
        if (target) run(target);
        avoid(px, py);
        if (!(x == r-1 && y == c-1)) run(-1);
    }
}