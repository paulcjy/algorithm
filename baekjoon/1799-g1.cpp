#include <bits/stdc++.h>

using namespace std;

int n, n_2, ans = 0, cnt = 0;
int board[10][10];
int uUsed[20];
int dUsed[20];

void bt(int k) {
    for (int i = k; i < n_2; i++) {
        if (i == n_2 - 1) {
            ans = max(ans, cnt);
            return;
        }
        int x = i / n;
        int y = i % n;
        int up = x + y;
        int down = x - y + n - 1;
        if (!board[x][y] || uUsed[up] || dUsed[down]) 
            continue;
        else {
            cnt++;
            uUsed[up] = 1;
            dUsed[down] = 1;
            bt(i+1);
            cnt--;
            uUsed[up] = 0;
            dUsed[down] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> board[i][j];
    n_2 = n * n;
    bt(0);
    cout << ans;
}