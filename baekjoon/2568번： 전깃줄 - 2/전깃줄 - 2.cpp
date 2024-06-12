#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;
#define X first
#define Y second

int n;
pi2 line[100'005];
vector<pi2> d(1, {0, 0}); // {idx, value}
int prv[500'005];
vi lis;
bool isLis[500'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> line[i].X >> line[i].Y;
    sort(line+1, line+n+1);
    
    for (int i = 1; i <= n; i++) {
        auto [a, b] = line[i];
        if (b > d.back().Y) {
            prv[a] = d.back().X;
            d.push_back({a, b});
        }
        else {
            int l = 0;
            int r = d.size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (d[mid].Y < b) l = mid + 1;
                else r = mid - 1;
            }
            d[l] = {a, b};
            prv[a] = d[l-1].X;
        }
    }
    cout << n - d.size() + 1 << '\n';

    int idx = d.back().X;
    while (idx != 0) {
        lis.push_back(idx);
        idx = prv[idx];
    }
    for (auto i : lis) isLis[i] = true;

    for (int i = 1; i <= n; i++) {
        auto [a, b] = line[i];
        if (isLis[a]) continue;
        cout << a << '\n';
    }


}