#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, k;

int divcows(int n) {
    if (n <= k || (n - k) & 1) return 1;
    else return divcows((n-k)>>1) + divcows((n+k)>>1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    cout << divcows(n);
}