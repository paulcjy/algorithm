#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, ans;
int w[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    sort(w, w+n);
    for (int i = 1; i <= n; i++)
        ans = max(ans, w[n-i] * i);
    cout << ans;
}