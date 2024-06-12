#include <bits/stdc++.h>
using namespace std;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
int d[1000005];
int p[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1] = 0;
    p[1] = 0;
    for (int i = 2; i <= n; i++) {
        d[i] = d[i-1] + 1;
        p[i] = i - 1;
        if (i % 3 == 0 && d[i/3] < d[i]) {
            d[i] = d[i/3] + 1;
            p[i] = i / 3;
        }
        if (i % 2 == 0 && d[i/2] < d[i]) {
            d[i] = d[i/2] + 1;
            p[i] = i / 2;
        }
    }
    cout << d[n] << '\n';
    int idx = n;
    while (idx != 1) {
        cout << idx << ' ';
        idx = p[idx];
    }
    cout << 1;
}