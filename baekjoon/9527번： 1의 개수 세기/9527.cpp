#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

ll a, b;
ll dp[70];

void filldp() {
    dp[0] = 1;
    for (int i = 1; i < 60; i++)
        dp[i] = (dp[i-1] << 1) + (1LL << (i-1)) - 1;
}

ll count1(ll n) {
    if (n < 3) return n;
    ll ret = 0;
    for (int i = 59; i >= 0; i--) {
        if (n & (1LL << i)) {
            n ^= 1LL << i;
            ret += dp[i] + n;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    filldp();
    cout << count1(b) - count1(a-1);
}