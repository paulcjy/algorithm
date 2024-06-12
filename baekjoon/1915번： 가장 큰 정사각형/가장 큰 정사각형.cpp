#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, m;
int a[1005][1005];
int d[1005][1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char input;
            cin >> input;
            a[i][j] = input - '0';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j]) {
                d[i][j] = min({d[i-1][j-1], d[i-1][j], d[i][j-1]}) + 1;
                if (d[i][j] == 0) d[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = max(ans, d[i][j]);
    cout << ans * ans;
}