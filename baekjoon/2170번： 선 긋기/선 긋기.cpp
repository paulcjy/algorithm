#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;
#define X first
#define Y second

int n, ans;
pi2 line[1'000'005];
vector<pi2> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> line[i].X >> line[i].Y;
    sort(line, line+n);
    auto [s, e] = line[0];
    for (int i = 1; i < n; i++) {
        auto [x, y] = line[i];
        if (x <= e) {
            if (y > e) e = y;
        }
        else {
            ans += e - s;
            s = x;
            e = y;
        }
    }
    ans += e - s;
    cout << ans;
}