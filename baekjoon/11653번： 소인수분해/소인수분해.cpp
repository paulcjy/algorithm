#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    if (n == 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << '\n';
            n /= i;
        }
    }
    if (n != 1) cout << n;
}