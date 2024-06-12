#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int t, n;
int fibo[42][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fibo[0][0] = 1;
    fibo[0][1] = 0;
    fibo[1][0] = 0;
    fibo[1][1] = 1;
    for (int i = 2; i <= 40; i++)
        for (int j = 0; j < 2; j++)
            fibo[i][j] = fibo[i-1][j] + fibo[i-2][j];

    cin >> t;
    while (t--) {
        cin >> n;
        cout << fibo[n][0] << ' ' << fibo[n][1] << '\n';
    }
}