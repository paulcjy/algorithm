#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int t, n;
ll buy, sell, stock;
int p[1'000'005];
int m[1'000'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        buy = sell = stock = 0;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> p[i];
        int M = p[n-1];
        m[n-1] = 0;
        for (int i = n-2; i >= 0; i--) {
            m[i] = M;
            M = max(M, p[i]);
        }
        for (int i = 0; i < n; i++) {
            if (p[i] < m[i]) {
                stock++;
                buy += p[i];
            }
            else {
                sell += stock * p[i];
                stock = 0;
            }
        }
        cout << sell - buy << '\n';
    }
}