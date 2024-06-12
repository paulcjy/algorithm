#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;
#define MOD 1'000'000'007

ll n, ans;
ll a[500'005];
ll s[500'005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += (s[i-1] * a[i]) % MOD;
        s[i] = (s[i-1] + a[i]) % MOD;
    }
    cout << ans % MOD;
}