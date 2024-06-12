#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int arr[20][20];
int prv[20][20];
int ori[20][20];
int n, ans = 0;
int row[17][2];
int col[17][2];
int up[32][2];
int down[32][2];
vector<pair<int, int>> v;

bool decEmpty(int r, int c) {
    if (!row[r][0] || !col[c][0] || !up[r+c][0] || !down[r-c+n-1][0]) return false;
    row[r][0]--;
    col[c][0]--;
    up[r+c][0]--;
    down[r-c+n-1][0]--;
    return true;
}
void incEmpty(int r, int c) {
    row[r][0]++;
    col[c][0]++;
    up[r+c][0]++;
    down[r-c+n-1][0]++;
}
bool decTotal(int r, int c) {
    if (!row[r][1] || !col[c][1] || !up[r+c][1] || !down[r-c+n-1][1]) return false;
    row[r][1]--;
    col[c][1]--;
    up[r+c][1]--;
    down[r-c+n-1][1]--;
    return true;
}
void incTotal(int r, int c) {
    row[r][1]++;
    col[c][1]++;
    up[r+c][1]++;
    down[r-c+n-1][1]++;
}

bool setStone(int r, int c, int v) {
    bool result = true;
    if (!decEmpty(r, c)) return false;
    if (v && !decTotal(r, c)) {
        incEmpty(r, c);
        return false;
    }
    arr[r][c] = v;
    // printf("set %d %d -> %d\n", r, c, v);
    return true;
}

void putStone() {
    // row
    for (int i = 0; i < n; i++) {
        if (row[i][0] == 0) continue;
        if (row[i][1] == 0) {
            for (int j = 0; j < n; j++)
                if (arr[i][j] == -1)
                    setStone(i, j, 0);
        }
        else if (row[i][0] == row[i][1]) {
            for (int j = 0; j < n; j++)
                if (arr[i][j] == -1)
                    setStone(i, j, 1);
        }
    }
    // col
    for (int i = 0; i < n; i++) {
        if (col[i][0] == 0) continue;
        if (col[i][1] == 0) {
            for (int j = 0; j < n; j++)
                if (arr[j][i] == -1)
                    setStone(j, i, 0);
        }
        else if (col[i][0] == col[i][1]) {
            for (int j = 0; j < n; j++)
                if (arr[j][i] == -1)
                    setStone(j, i, 1);
        }
    }
    // up
    for (int k = 0; k < 2*n-1; k++) {
        if (up[k][0] == 0) continue;
        if (k < n) {
            if (up[k][1] == 0) {
                for (int i = 0; i <= k; i++)
                    if (arr[i][k-i] == -1)
                        setStone(i, k-i, 0);
            }
            else if (up[k][0] == up[k][1]) {
                for (int i = 0; i <= k; i++)
                    if (arr[i][k-i] == -1)
                        setStone(i, k-i, 1);
            }
        }
        else {
            if (up[k][1] == 0) {
                for (int i = k-n+1; i < n; i++)
                    if (arr[i][k-i] == -1)
                        setStone(i, k-i, 0);
            }
            else if (up[k][0] == up[k][1]) {
                for (int i = k-n+1; i < n; i++)
                    if (arr[i][k-i] == -1)
                        setStone(i, k-i, 1);

            }
        }
    }
    // down
    for (int k = 0; k < 2*n-1; k++) {
        if (down[k][0] == 0) continue;
        if (k < n) {
            if (down[k][1] == 0) {
                for (int i = 0; i <= k; i++)
                    if (arr[i][i-k+n-1] == -1)
                        setStone(i, i-k+n-1, 0);
            }
            else if (down[k][0] == down[k][1]) {
                for (int i = 0; i <= k; i++)
                    if (arr[i][i-k+n-1] == -1)
                        setStone(i, i-k+n-1, 1);
            }
        }
        else {
            if (down[k][1] == 0) {
                for (int i = k-n+1; i < n; i++)
                    if (arr[i][i-k+n-1] == -1)
                        setStone(i, i-k+n-1, 0);
            }
            else if (down[k][0] == down[k][1]) {
                for (int i = k-n+1; i < n; i++)
                    if (arr[i][i-k+n-1] == -1)
                        setStone(i, i-k+n-1, 1);
            }
        }
    }
}

void copyArr(int (&arr)[20][20], int (&prv)[20][20]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            prv[i][j] = arr[i][j];
}

bool isDiff(int (&a)[20][20], int (&b)[20][20]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != b[i][j])
                return true;
    return false;
}

int checkNum(int t) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] == t) cnt++;
    return cnt;
}

int bfs() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(i == 0 || i == n-1 || j == 0 || j == n-1)) continue;
            if (arr[i][j]) continue;
            queue<pair<int, int>> q;
            q.push({i, j});
            arr[i][j] = 1;
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = cur.X + dx[d];
                    int ny = cur.Y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (arr[nx][ny]) continue;
                    q.push({nx, ny});
                    arr[nx][ny] = 1;
                }
            }
        }
    }
    return checkNum(0);
}

void getInput() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> row[i][1];
        row[i][0] = n;
    }
    for (int i = 0; i < n; i++) {
        cin >> col[i][1];
        col[i][0] = n;
    }
    for (int i = 0; i < 2*n-1; i++) {
        cin >> up[i][1];
        if (i < n) up[i][0] = i + 1;
        else up[i][0] = 2*n - i - 1;
    }
    for (int i = 0; i < 2*n-1; i++) {
        cin >> down[2*n-2-i][1];
        if (i < n) down[i][0] = i + 1;
        else down[i][0] = 2*n - i - 1;
    }
}
void printStones() {
    cout << "row\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) 
            cout << row[j][i] << ' ';
        cout << '\n';
    }
    cout << "\ncol\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++)
            cout << col[j][i] << ' ';
        cout << '\n';
    }
    cout << "\ninc\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2*n-1; j++)
            cout << up[j][i] << ' ';
        cout << '\n';
    }
    cout << "\ndec\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2*n-1; j++)
            cout << down[j][i] << ' ';
        cout << '\n';
    }
    cout << '\n';
}
void printArr(int (&arr)[20][20]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

bool bt(int depth, int s) {
    if (depth == s) {
        // copyArr(arr, prv);
        return true;
    }
    auto [r, c] = v[depth];
    if (setStone(r, c, 1)) 
        if (bt(depth+1, s))
            return true;
    if (setStone(r, c, 0)) 
        if (bt(depth+1, s))
            return true;
    return false;
}

void getInput2() {
    for (int i = 0; i < n; i++) 
        row[i][0] = n;
    for (int i = 0; i < n; i++) 
        col[i][0] = n;
    for (int i = 0; i < 2*n-1; i++) 
        if (i < n) up[i][0] = i + 1;
        else up[i][0] = 2*n - i - 1;
    for (int i = 0; i < 2*n-1; i++) 
        if (i < n) down[i][0] = i + 1;
        else down[i][0] = 2*n - i - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // n = 4;
    // // int t = 43036;
    // for (int t = (1<<15); t < (1 << 16); t++) {
    //     int brute = t;
    //     for (int x = 0; x < n; x++) {
    //         for (int y = 0; y < n; y++) {
    //             arr[x][y] = brute & 0b01;
    //             brute >>= 1;
    //         }
    //     }
    //     getInput2();
    //     copyArr(arr, ori);

    //     for (int i = 0; i < n; i++)
    //         for (int j = 0; j < n; j++)
    //             if (arr[i][j] == 1)
    //                 incTotal(i, j);

    //     memset(arr, -1, sizeof(arr));
    //     memset(prv, 0, sizeof(prv));
    //     // getInput();
    //     do {
    //         copyArr(arr, prv);
    //         putStone();
    //     } while (isDiff(arr, prv));

    //     v.clear();
    //     for (int i = 0; i < n; i++)
    //         for (int j = 0; j < n; j++)
    //             if (arr[i][j] == -1)
    //                 v.push_back({i, j});
    //     if (v.size() > 0) {
    //         // cout << v.size() << '\n';
    //         // printArr(arr);
    //         bt(0, v.size());
    //     }
    //     // copyArr(prv, arr);
    //     if (isDiff(arr, ori)) {
    //         cout << "error t: " << t << '\n';
    //         printArr(ori);
    //         printArr(arr);
    //     }
    //     // ans = bfs();
    //     // cout << ans;
    // }
        memset(arr, -1, sizeof(arr));
        getInput();
        do {
            copyArr(arr, prv);
            putStone();
        } while (isDiff(arr, prv));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (arr[i][j] == -1)
                    v.push_back({i, j});
        if (v.size() > 0) bt(0, v.size());
        // copyArr(prv, arr);
        // printArr(arr);
        ans = bfs();
        cout << ans;
}