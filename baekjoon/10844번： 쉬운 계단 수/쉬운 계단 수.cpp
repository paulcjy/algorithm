#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
ll d[105][10];
ll c = 1000000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1][0] = 0;
    for (int i = 1; i < 10; i++) d[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j != 0) d[i][j] += d[i-1][j-1];
            if (j != 9) d[i][j] += d[i-1][j+1];
            d[i][j] %= c;
        }
    }
    ll ans = 0;
    for (int i = 0; i < 10; i++)
        ans += d[n][i];
    cout << ans % c;
}