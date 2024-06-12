#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
int t[1500005];
int p[1500005];
int d[1500005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i] >> p[i];
    for (int i = n-1; i >= 0; i--) {
        if (i + t[i] <= n)
            d[i] = max(d[i+t[i]] + p[i], d[i+1]);
        else
            d[i] = d[i+1];
    }
    cout << *max_element(d, d+n);
}