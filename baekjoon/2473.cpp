#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
ll sol[5005];
ll m = LONG_MAX;
tuple<ll, ll, ll> mv;

int bs(int l, int r, ll t) {
    int fl = l, fr = r;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (t == sol[mid]) return mid;
        else if (t > sol[mid]) l = mid;
        else r = mid;
    }
    if (l == fl) return l+1;
    else if (r == fr) return r-1;
    else return t - sol[l] < sol[r] - t ? l : r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> sol[i];
    sort(sol, sol+n);
    for (int l = 0; l < n-2; l++) {
        for (int r = l+2; r < n; r++) {
            ll sum = sol[l] + sol[r];
            int mid = bs(l, r, -sum);
            sum += sol[mid];
            if (abs(sum) < m) {
                m = abs(sum);
                mv = {sol[l], sol[mid], sol[r]};
            }
        }
    }
    auto [m1, m2, m3] = mv;
    cout << m1 << ' ' << m2 << ' ' << m3;
}