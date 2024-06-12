#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;
#define MOD 1'000'000'003

int n, k;
int d[1005][1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    if (k > (n >> 1)) { cout << 0; return 0; }
    for (int i = 0; i <= n; i++) {
        d[i][0] = 1;
        d[i][1] = i;
    }
    d[2][2] = 0;
    for (int i = 4; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            d[i][j] = (d[i-1][j] + d[i-2][j-1]) % MOD;
        }
    }
    cout << d[n][k];
}