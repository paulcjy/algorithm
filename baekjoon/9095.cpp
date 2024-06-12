// dp
#include <bits/stdc++.h>
using namespace std;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int dp[12];
int t, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 12; i++)
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];

    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}