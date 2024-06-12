#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, ans;
int p[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p, p+n);
    ans = p[0];
    for (int i = 1; i < n; i++) {
        p[i] += p[i-1];
        ans += p[i];
    }
    cout << ans;
}