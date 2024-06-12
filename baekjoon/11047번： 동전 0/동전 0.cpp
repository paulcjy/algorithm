#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, k, ans;
int coin[12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = n-1; i >= 0; i--)
        cin >> coin[i];
    for (int i = 0; i < n; i++) {
        ans += k / coin[i];
        k %= coin[i];
    }
    cout << ans;
}