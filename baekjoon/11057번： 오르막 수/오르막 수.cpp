#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, ans;
int d[1005][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < 10; i++)
        d[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        d[i][0] = 1;
        for (int j = 1; j < 10; j++)
            d[i][j] = (d[i][j-1] + d[i-1][j]) % 10007;
    }
    for (int i = 0; i < 10; i++)
        ans += d[n][i];
    cout << ans % 10007;
}