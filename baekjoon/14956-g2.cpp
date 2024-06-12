#include <bits/stdc++.h>

using namespace std;

void walk(int n, int m, int x, int y) {
    if (n == 2) {
        if (m == 1) cout << x << ' ' << y;
        else if (m == 2) cout << x << ' ' << y+1;
        else if (m == 3) cout << x+1 << ' ' << y+1;
        else cout << x+1 << ' ' << y;
        return;
    }
    n /= 2;
    int quarter = n * n;
    if (m <= quarter)
        walk(n, m, x, y);
    else if (m <= quarter * 2)
        walk(n, m-quarter, x, y+n);
    else if (m <= quarter * 3)
        walk(n, m-(2*quarter), x+n, y+n);
    else
        walk(n, m-(3*quarter), 2*n-y+1, n-x+1);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    walk(n, m, 1, 1);

    return 0;
}