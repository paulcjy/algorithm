#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
ll sol[5005];
ll mn = LLONG_MAX;
ti3 mi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> sol[i];
    sort(sol, sol+n);
    for (int l = 0; l < n-2; l++) {
        int m = l + 1;
        int r = n - 1;
        while (m < r) {
            ll sum = sol[l] + sol[m] + sol[r];
            ll abssum = abs(sum);
            if (abssum < mn) {
                mn = abssum;
                mi = {l ,m, r};
            }
            if (sum > 0) r--;
            else m++;
        }
    }
    auto [m1, m2, m3] = mi;
    cout << sol[m1] << ' ' << sol[m2] << ' ' << sol[m3];
}