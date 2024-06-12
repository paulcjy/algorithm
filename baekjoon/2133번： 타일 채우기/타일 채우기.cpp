#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
int d[35];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[0] = 1;
    d[2] = 3;
    for (int i = 4; i < 31; i += 2)
        d[i] = d[i-2] * 4 - d[i-4];
    cout << d[n];
}