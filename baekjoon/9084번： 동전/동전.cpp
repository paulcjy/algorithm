#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int t, n, m;
int coin[25];
int d[10'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> coin[i];
        cin >> m;
        
        memset(d, 0, sizeof(d));
        d[0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = coin[i]; j <= m ; j++)
                d[j] += d[j-coin[i]];
        cout << d[m] << '\n';
    }
}