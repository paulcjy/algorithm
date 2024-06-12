#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, m, ans = 1;
int vip[45];
int d[45];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) 
        cin >> vip[i];
    vip[m+1] = n + 1;
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++)
        d[i] = d[i-1] + d[i-2];
    for (int i = 1; i <= m+1; i++) ans *= d[vip[i] - vip[i-1] - 1];
    cout << ans;
}