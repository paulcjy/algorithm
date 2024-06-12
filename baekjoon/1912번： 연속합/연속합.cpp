#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, ans;
int a[100005];
int d[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    d[0] = ans = a[0];
    for (int i = 1; i < n; i++) {
        d[i] = max(d[i-1] + a[i], a[i]);
        ans = max(ans, d[i]);
    }
    cout << ans;
}