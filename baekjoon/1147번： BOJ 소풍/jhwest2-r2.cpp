#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

int n, m;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i % 2 != j % 2) continue;
            int a = i / gcd(i, j);
            int b = j / gcd(i, j);
            int s = 0;
            if (i % 2) {
                s = 2 * min((i + b) / (2 * b), (j + a) / (2 * a));
                s += 2 * min((i + b - 1) / (2 * b), (j + a - 1) / (2 * a));
                if (i == j) s -= 1;
            }
            else {
                s = 2 * min(i / 2 / b, j / 2 / a) + 1;
                s += 2 * min((i - 1) / (2 * b), (j - 1) / (2 * a));
                if (i == j) s -= 1;
            }
            ans += s * (n - i + 1) * (m - j + 1);
        }
    }
    cout << ans;
}