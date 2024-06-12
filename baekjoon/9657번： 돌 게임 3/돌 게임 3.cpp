#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
int d[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1] = 1;
    d[2] = 0;
    d[3] = 1;
    d[4] = 1;
    for (int i = 5; i <= n; i++) {
        if (d[i-4] == 0 || d[i-3] == 0 || d[i-1] == 0) d[i] = 1;
        else d[i] = 0;
    }
    cout << (d[n] == 1 ? "SK" : "CY");
}