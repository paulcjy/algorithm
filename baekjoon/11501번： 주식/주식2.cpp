#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int t, n;
ll buy, sell, stock;
int p[1'000'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        buy = sell = stock = 0;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> p[i];
        int M = 0;
        for (int i = n-1; i >= 0; i--) {
            if (p[i] > M) {//sell;
                sell += M * stock;
                stock = 0;
                M = p[i];
            }
            else {
                stock++;
                buy += p[i];
            }
        }
        sell += M * stock;
        cout << sell - buy << '\n';
    }
}