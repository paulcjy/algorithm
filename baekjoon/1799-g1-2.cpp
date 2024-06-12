#include <bits/stdc++.h>

using namespace std;

int n, n_2;
int ans[2], cnt[2];
int arr[2][10][10];
int uUsed[2][20];
int dUsed[2][20];

void bt(int k, int color) {
    for (int i = k; i <= n_2; i++) {
        if (i == n_2) {
            ans[color] = max(ans[color], cnt[color]);
            return;
        }
        int x = i / n;
        int y = i % n;
        int up = x + y;
        int down = x - y + n - 1;
        if (!arr[color][x][y] || uUsed[color][up] || dUsed[color][down]) 
            continue;
        else {
            cnt[color]++;
            uUsed[color][up] = 1;
            dUsed[color][down] = 1;
            bt(i+1, color);
            cnt[color]--;
            uUsed[color][up] = 0;
            dUsed[color][down] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> arr[(i+j)%2][i][j];
    n_2 = n * n;
    bt(0, 0);
    bt(0, 1);
    cout << ans[0] + ans[1];
}