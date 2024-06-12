#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int m, n;
vector<bool> isPrime(1'000'005, true);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;
    isPrime[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= n; j += i) isPrime[j] = false;
    }
    for (int i = m; i <= n; i++) if (isPrime[i]) cout << i << '\n';
}