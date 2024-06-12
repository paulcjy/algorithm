#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, m, s, e;
int a[2'005];
int d[2'005][2'005];

void pal(int s, int e) {
    while (0 < s && e < n+1)
        if (a[s] == a[e]) d[s--][e++] = 1;
        else break;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        pal(i, i);
        if (a[i] == a[i+1]) pal(i, i+1);
    }
    cin >> m;
    while (m--) {
        cin >> s >> e;
        cout << d[s][e] << '\n';
    }
}