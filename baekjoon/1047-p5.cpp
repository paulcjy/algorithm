#include <bits/stdc++.h>

using namespace std;

int n, tree[40][3], xM, yM, xm = 1000000, ym = 1000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, l;
        cin >> x >> y >> l;
        tree[i][0] = x;
        tree[i][1] = y;
        tree[i][2] = l;
        if (x > xM) xM = x;
        if (y > yM) yM = y;
        if (x < xm) xm = x;
        if (y < ym) ym = y;
    }
    cout << "필요 길이: " << 2*(xM+yM-xm-ym);

    return 0;
}