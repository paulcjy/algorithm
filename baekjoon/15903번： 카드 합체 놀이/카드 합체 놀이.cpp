#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, m;
ll s[1005];
ll ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];

    while (m--) {
        sort(s, s+n);
        s[0] = s[1] = s[0] + s[1];
    }
    for (int i = 0; i < n; i++) ans += s[i];
    cout << ans;
}