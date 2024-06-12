#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
int d[1000005];
bool neg;
int c = 1'000'000'000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if (n == 0) {
        cout << "0\n0";
        return 0;
    }
    neg = n < 0;
    if (neg) n = -n;
    d[1] = 1;
    for (int i = 2; i <= n; i++)
        d[i] = (d[i-1] + d[i-2]) % c;
    cout <<  ((neg && n % 2 == 0) ? -1 : 1) << '\n' << d[n];
}