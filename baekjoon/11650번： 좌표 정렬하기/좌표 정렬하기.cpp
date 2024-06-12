#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
pi2 p[100'005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    sort(p, p+n);
    for (int i = 0; i < n; i++) cout << p[i].first << ' ' << p[i].second << '\n';
}