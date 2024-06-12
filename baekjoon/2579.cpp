// dp
#include <bits/stdc++.h>
using namespace std;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int s[305];
int dp[305][3];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    
    dp[0][1] = s[0];
    dp[0][2] = 0;
    dp[1][1] = s[1];
    dp[1][2] = s[0] + s[1];
    for (int i = 2; i < n; i++) {
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + s[i];
        dp[i][2] = dp[i-1][1] + s[i];
    }
    cout << max(dp[n-1][1], dp[n-1][2]);
}