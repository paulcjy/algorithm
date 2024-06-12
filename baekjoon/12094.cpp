// back tracking
#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;
int arr[22][22];
int run[22][22];
int dir[10];

void rotate(int dir) {
    if (dir == 0) return;
    int tmp[22][22];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = run[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dir == 1)
                run[i][j] = tmp[n-1-j][i];
            else if (dir == 2)
                run[i][j] = tmp[n-1-j][n-1-i];
            else
                run[i][j] = tmp[j][n-1-i];
}

void tilt(int dir) {
    rotate(dir);
    for (int i = 0; i < n; i++) {
        int result[22] = {};
        int idx = 0;
        for (int j = 0; j < n; j++) {
            if (run[i][j] == 0) continue;
            if (result[idx] == 0)
                result[idx] = run[i][j];
            else if (result[idx] == run[i][j])
                result[idx++] <<= 1;
            else
                result[++idx] = run[i][j];
        }
        for (int j = 0; j < n; j++)
            run[i][j] = result[j];
    }
}

void bt(int k) {
    if (k == 10) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                run[i][j] = arr[i][j];
        for (int i = 0; i < 10; i++) 
            tilt(dir[i]);
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                ans = max(ans, run[i][j]);
        return;
    }
    for (int i = 0; i < 4; i++) {
        dir[k] = i;
        bt(k+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j];
    bt(0);
    cout << ans;
}