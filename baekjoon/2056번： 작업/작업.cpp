
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
int t[10'005];
int d[10'005];
vi pre[10'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cnt, j;
        cin >> t[i] >> cnt;
        while (cnt--) {
            cin >> j;
            pre[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; i++) if (!pre[i].size()) d[i] = t[i];
    for (int i = 1; i <= n; i++) {
        for (auto p : pre[i])
            d[i] = max(d[i], d[p] + t[i]);
    }
    cout << *max_element(d+1, d+n+1);
}