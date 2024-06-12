#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

enum Status {
    T,
    C,
    E
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ori[20][20];
int arr[20][20];
int prv[20][20];
int n;
int row[17][3];
int col[17][3];
int up[32][3];
int down[32][3];
int ans = 0;

void decEmpty(int r, int c) {
    row[r][E]--;
    col[c][E]--;
    up[r+c][E]--;
    down[r-c+n-1][E]--;
}
void decTotal(int r, int c) {
    row[r][T]--;
    col[c][T]--;
    up[r+c][T]--;
    down[r-c+n-1][T]--;
}
void incTotal(int r, int c) {
    row[r][T]++;
    col[c][T]++;
    up[r+c][T]++;
    down[r-c+n-1][T]++;
}
void incCur(int r, int c) {
    row[r][C]++;
    col[c][C]++;
    up[r+c][C]++;
    down[r-c+n-1][C]++;
}

void setStone(int r, int c, int value) {
    if (value == 1) {
        arr[r][c] = 1;
        decTotal(r, c);
        incCur(r, c);
        decEmpty(r, c);
    }
    else {
        arr[r][c] = 0;
        decEmpty(r, c);
    }
}

void putStone() {
    // row
    for (int i = 0; i < n; i++) {
        if (row[i][E] == 0) continue;
        if (row[i][T] == 0) {
            for (int j = 0; j < n; j++)
                if (arr[i][j] == -1)
                    setStone(i, j, 0);
        }
        else if (row[i][T] == row[i][E]) {
            for (int j = 0; j < n; j++)
                if (arr[i][j] == -1)
                    setStone(i, j, 1);
        }
    }
    // col
    for (int i = 0; i < n; i++) {
        if (col[i][E] == 0) continue;
        if (col[i][T] == 0) {
            for (int j = 0; j < n; j++)
                if (arr[j][i] == -1)
                    setStone(j, i, 0);
        }
        else if (col[i][T] == col[i][E]) {
            for (int j = 0; j < n; j++)
                if (arr[j][i] == -1)
                    setStone(j, i, 1);
        }
    }
    // up
    for (int k = 0; k < 2*n-1; k++) {
        if (up[k][E] == 0) continue;
        if (k < n) {
            if (up[k][T] == 0) {
                for (int i = 0; i <= k; i++)
                    if (arr[i][k-i] == -1)
                        setStone(i, k-i, 0);
            }
            else if (up[k][T] == up[k][E]) {
                for (int i = 0; i <= k; i++)
                    if (arr[i][k-i] == -1)
                        setStone(i, k-i, 1);
            }
        }
        else {
            if (up[k][T] == 0)
                for (int i = k-n+1; i <= n-1; i++)
                    if (arr[i][k-i] == -1)
                        setStone(i, k-i, 0);
            if (up[k][T] == up[k][E])
                for (int i = k-n+1; i <= n-1; i++)
                    if (arr[i][k-i] == -1)
                        setStone(i, k-i, 1);
        }
    }
    // down
    for (int k = 0; k < 2*n-1; k++) {
        if (down[k][E] == 0) continue;
        if (k < n) {
            if (down[k][T] == 0)
                for (int i = 0; i <= k; i++)
                    if (arr[i][i-k+n-1] == -1)
                        setStone(i, i-k+n-1, 0);
            if (down[k][T] == down[k][E])
                for (int i = 0; i <= k; i++)
                    if (arr[i][i-k+n-1] == -1)
                        setStone(i, i-k+n-1, 1);
        }
        else {
            if (down[k][T] == 0) {
                for (int i = k-n+1; i <= n-1; i++)
                    if (arr[i][i-k+n-1] == -1)
                        setStone(i, i-k+n-1, 0);
            }
            else if (down[k][T] == down[k][E]) {
                for (int i = k-n+1; i <= n-1; i++)
                    if (arr[i][i-k+n-1] == -1)
                        setStone(i, i-k+n-1, 1);
            }
        }
    }
}

void copyArr(int (&arr)[20][20], int (&prev)[20][20]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            prev[i][j] = arr[i][j];
}

bool compareArr(int (&a)[20][20], int (&b)[20][20]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != b[i][j])
                return true;
    return false;
}

void printStones() {
    cout << "row\n";
    for (int i = 0; i < 3; i++) {
        if (i == 1) continue;
        for (int j = 0; j < n; j++) 
            cout << row[j][i] << ' ';
        cout << '\n';
    }
    cout << "\ncol\n";
    for (int i = 0; i < 3; i++) {
        if (i == 1) continue;
        for (int j = 0; j < n; j++)
            cout << col[j][i] << ' ';
        cout << '\n';
    }
    cout << "\ninc\n";
    for (int i = 0; i < 3; i++) {
        if (i == 1) continue;
        for (int j = 0; j < 2*n-1; j++)
            cout << up[j][i] << ' ';
        cout << '\n';
    }
    cout << "\ndec\n";
    for (int i = 0; i < 3; i++) {
        if (i == 1) continue;
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

int bfs() {
    int cnt = 0;
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
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] == 0) cnt++;
    return cnt;
}

int checkZero() {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] == 0) cnt++;
    return cnt;
}

void getInput() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> row[i][T];
        row[i][E] = n;
    }
    for (int i = 0; i < n; i++) {
        cin >> col[i][T];
        col[i][E] = n;
    }
    for (int i = 0; i < 2*n-1; i++) {
        cin >> up[i][T];
        if (i < n) up[i][E] = i + 1;
        else up[i][E] = 2*n - i - 1;
    }
    for (int i = 0; i < 2*n-1; i++) {
        cin >> down[2*n-2-i][T];
        if (i < n) down[i][E] = i + 1;
        else down[i][E] = 2*n - i - 1;
    }
}

void getInput2() {
    for (int i = 0; i < n; i++) 
        row[i][E] = n;
    for (int i = 0; i < n; i++) 
        col[i][E] = n;
    for (int i = 0; i < 2*n-1; i++) 
        if (i < n) up[i][E] = i + 1;
        else up[i][E] = 2*n - i - 1;
    for (int i = 0; i < 2*n-1; i++) 
        if (i < n) down[i][E] = i + 1;
        else down[i][E] = 2*n - i - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    n = 4;
    // int t = 0x4182;
    // int t = 10262;
    int l = 1 << 16;
    for (int t = l - 15000; t < l; t++) {
        int brute = t;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                arr[x][y] = brute & 0b01;
                brute >>= 1;
            }
        }
        getInput2();
        copyArr(arr, ori);
        
        // count
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                if (arr[i][j] == 1) 
                    incTotal(i, j);

        memset(arr, -1, sizeof(arr));
        memset(prv, 0, sizeof(prv));
        do {
            copyArr(arr, prv);
            putStone();
        } while (compareArr(arr, prv));

        if (compareArr(arr, ori)) {
            cout << "error! t: " << t << '\n';
            printArr(ori);
            // printArr(arr);
            // printStones();
        }
    }


    // ans = bfs();
    // cout << ans;
}