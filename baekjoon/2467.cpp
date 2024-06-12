#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
int sol[100'005];
int m = INT_MAX;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> sol[i];
    int l, r, ml, mr;
    l = ml = 0;
    r = mr = n-1;
    while (l < r) {
        int sum = sol[l] + sol[r];
        if (abs(sum) < abs(sol[ml] + sol[mr])) { ml = l; mr = r; }
        if (sum == 0) break;
        if (sum > 0) r--;
        else l++;
    }
    cout << sol[ml] << ' ' << sol[mr];
}