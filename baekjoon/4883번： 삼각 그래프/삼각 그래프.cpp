#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, t;
int g[100'005][3];
int d[100'005][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (++t) {
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                cin >> g[i][j];
        d[0][0] = INT_MAX;
        d[0][1] = g[0][1];
        d[0][2] = g[0][1] + g[0][2];
        for (int i = 1; i < n; i++) {
            d[i][0] = min(d[i-1][0], d[i-1][1]) + g[i][0];
            d[i][1] = min({d[i-1][0], d[i-1][1], d[i-1][2], d[i][0]}) + g[i][1];
            d[i][2] = min({d[i-1][1], d[i-1][2], d[i][1]}) + g[i][2];
        }
        cout << t << ". " << d[n-1][1] << '\n';
    }
}