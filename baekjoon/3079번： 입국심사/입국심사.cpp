#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

ll n, m, ans = 1e18 + 1;
int t[100'005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> t[i];
    ll l = 0, r = 1e18 + 1;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        ll s = 0;
        for (int i = 0; i < n; i++) {
            s += mid / t[i];
            if (s >= m) break;
        }
        if (s >= m) r = mid;
        else l = mid;
    }
    cout << r;
}