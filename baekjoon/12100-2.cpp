// back tracking - bit
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j];
    for (int tmp = 0; tmp < 1024; tmp++) {
        int brute = tmp;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                run[i][j] = arr[i][j];
        for (int i = 0; i < 5; i++) {
            int dir = brute % 4;
            brute /= 4;
            tilt(dir);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, run[i][j]);
    }
    cout << ans;
}