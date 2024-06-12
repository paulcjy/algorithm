#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
int tri[505][505];
int d[505][505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> tri[i][j];
    d[1][1] = tri[1][1];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            d[i][j] = max(d[i-1][j], d[i-1][j-1]) + tri[i][j];
    cout << *max_element(d[n], d[n]+n+1);
}