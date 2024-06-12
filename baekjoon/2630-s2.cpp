#include <bits/stdc++.h>

using namespace std;

int arr[130][130];
int w, b;

void cut(int n, int r, int c) {
    if (n == 1) {
        arr[r][c] ? b++ : w++;
        return;
    }

    int start = arr[r][c];
    int flipped = 0;
    for (int i = r; i < r+n; i++) 
        for (int j = c; j < c+n; j++) 
            if (arr[i][j] != start) flipped++;

    if (flipped == 0) arr[r][c] ? b++ : w++;
    else {
        n /= 2;
        cut(n, r, c);
        cut(n, r+n, c);
        cut(n, r, c+n);
        cut(n, r+n, c+n);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j];

    cut(n, 0, 0);
    cout << w << '\n' << b;
    return 0;
}