#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int t, n;
ll d[1000005];
int c = 1000000009;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int i = 4; i < 1000005; i++)
        d[i] = (d[i-3] + d[i-2] + d[i-1]) % c;

    cin >> t;
    while (t--) {
        cin >> n;
        cout << d[n] << '\n';
    }
}