#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
int d[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[0] = 1;
    d[1] = 3;
    cin >> n;
    for (int i = 2; i < n; i++)
        d[i] = (d[i-1] + 2*d[i-2]) % 10007;
    cout << d[n-1];
}