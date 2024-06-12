#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int t, n;
int s[2][100'005];
int d[2][100'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < n; j++) 
                cin >> s[i][j];
        d[0][0] = s[0][0];
        d[1][0] = s[1][0];
        d[0][1] = d[1][0] + s[0][1];
        d[1][1] = d[0][0] + s[1][1];
        for (int i = 2; i < n; i++) {
            d[0][i] = max(d[1][i-1], d[1][i-2]) + s[0][i];
            d[1][i] = max(d[0][i-1], d[0][i-2]) + s[1][i];
        }
        cout << max(d[0][n-1], d[1][n-1]) << '\n';
    }
}