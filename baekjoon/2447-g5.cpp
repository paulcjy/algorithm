#include <bits/stdc++.h>

using namespace std;

char arr[2200][2200];

void star(int n, int r, int c) {
    if (n == 1) {
        arr[r][c] = '*';
        return;
    }
    n /= 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            star(n, r+n*i, c+n*j);
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(arr, ' ', sizeof(arr));

    int n;
    cin >> n;
    star(n, 0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}