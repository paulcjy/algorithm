#include <bits/stdc++.h>

using namespace std;

int arr[65][65];

void zip(int n, int r, int c) {
    int first = arr[r][c];

    if (n == 1) {
        cout << first;
        return;
    }

    int flipped = 0;
    for (int i = r; i < r+n; i++) 
        for (int j = c; j < c+n; j++) 
            if (arr[i][j] != first) flipped++;
    if (flipped == 0) {
        cout << first;
        return;
    }

    cout << '(';
    n /= 2;
    zip(n, r, c);
    zip(n, r, c+n);
    zip(n, r+n, c);
    zip(n, r+n, c+n);
    cout << ')';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char input;
            cin >> input;
            arr[i][j] = input - '0';
        }
    }
    zip(n, 0, 0);
    return 0;
}