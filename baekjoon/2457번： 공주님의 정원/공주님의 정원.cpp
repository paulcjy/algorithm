#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;
#define X first
#define Y second

int n;
vector<pi2> flower;
vector<pi2> garden;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int day(int m, int d) {
    int ret = 0;
    for (int i = 0; i < m; i++) ret += month[i];
    return ret + d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int pstart = day(3, 1);
    int pend = day(12, 1);
    int startmin = 366;
    int endmax = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int m1, d1, m2, d2;
        cin >> m1 >> d1 >> m2 >> d2;
        int fstart = day(m1, d1);
        int fend = day(m2, d2);
        if (fend <= pstart || pend <= fstart ) continue;
        flower.push_back({fstart, fend});
        startmin = min(startmin, fstart);
        endmax = max(endmax, fend);
    }

    if (startmin > pstart || endmax < pend || flower.size() == 0) {
        cout << 0;
        return 0;
    }

    sort(flower.begin(), flower.end());

    garden.push_back({0, day(3, 1)});
    for (int i = 0; i < flower.size(); ) {
        auto [ps, pe] = garden.back();
        if (pe >= pend) break;
        int s = 0, e = 0;
        while (i < flower.size()) {
            auto [cs, ce] = flower[i];
            if (cs <= pe) {
                if (ce > e) { s = cs; e = ce; }
                i++;
            }
            else break;
        }
        if (!s && !e) break;
        garden.push_back({s, e});
    }
    if (garden.back().Y >= pend) cout << garden.size() - 1;
    else cout << 0;
}