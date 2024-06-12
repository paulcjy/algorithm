#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, k;
int d[10'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    vi c(n);
    for (auto& e : c) cin >> e;
    c.erase(unique(c.begin(), c.end()), c.end());
    sort(c.begin(), c.end());
    
    for (auto e : c) if (e <= 10000) d[e] = 1;
    for (int i = c[0] + 1; i <= k; i++)
        for (int j = 1; j < i/2 + 1; j++) 
            if (d[j] && d[i-j])
                d[i] = d[i] ? min(d[i], d[j] + d[i-j]) : d[j] + d[i-j];
    cout << (d[k] ? d[k] : -1);
}