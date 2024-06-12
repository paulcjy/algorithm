#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
int d[100'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < 4; i++) d[i] = i;
    for (int i = 4; i <= n; i++) {
        d[i] = d[i-1] + 1;
        for (int j = 1; j*j <= i; j++)
            d[i] = min(d[i], d[i-j*j] + 1);
    }
    cout << d[n];
}