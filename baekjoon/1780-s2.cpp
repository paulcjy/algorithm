#include <bits/stdc++.h>

using namespace std;

int arr[2200][2200];
int m, z, p;

void cut(int n, int r, int c) {
    int first = arr[r][c];
    int flipped = 0;
    for (int i = r; i < r+n; i++) 
        for (int j = c; j < c+n; j++) 
            if (first != arr[i][j]) flipped++;

    if (n == 1 || flipped == 0) {
        if (first == -1) m++;
        else if (first == 0) z++;
        else if (first == 1) p++;
        return;
    }

    n /= 3;
    cut(n, r, c);
    cut(n, r, c+n);
    cut(n, r, c+n+n);
    cut(n, r+n, c);
    cut(n, r+n, c+n);
    cut(n, r+n, c+n+n);
    cut(n, r+n+n, c);
    cut(n, r+n+n, c+n);
    cut(n, r+n+n, c+n+n);
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
    cout << m << '\n' << z << '\n' << p;

    return 0;
}