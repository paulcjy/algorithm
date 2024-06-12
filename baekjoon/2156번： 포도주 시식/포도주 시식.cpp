#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
int a[10005];
int d[10005][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    d[0][0] = 0;
    d[0][1] = a[0];
    for (int i = 1; i < n; i++) {
        d[i][0] = max({d[i-1][0], d[i-1][1], d[i-1][2]});
        d[i][1] = d[i-1][0] + a[i];
        d[i][2] = d[i-1][1] + a[i];
    }
    n--;
    cout << max({d[n][0], d[n][1], d[n][2]});
}