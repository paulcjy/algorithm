#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, k, coin;
int d[10'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[0] = 1;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coin;
        for (int j = coin; j <= k; j++) 
            d[j] += d[j-coin];
    }
    cout << d[k];
}