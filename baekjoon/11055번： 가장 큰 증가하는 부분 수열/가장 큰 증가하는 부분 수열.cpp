#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, ans;
int a[1005];
int d[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d[i] = a[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i] > a[j]) d[i] = max(d[i], d[j]+a[i]);
    cout << *max_element(d, d+n);
}