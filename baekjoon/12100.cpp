// back tracking
#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;
int arr[22][22];
int run[22][22];
int dir[5];

void rotate() {
    int tmp[22][22];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = run[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            run[i][j] = tmp[n-j-1][i];
}

void tilt(int dir) {
    while (dir--) rotate();
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
    if (k == 5) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                run[i][j] = arr[i][j];
        for (int i = 0; i < 5; i++) 
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