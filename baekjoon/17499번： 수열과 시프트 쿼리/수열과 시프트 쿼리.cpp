#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, q, st, cmd, i, x, sh;
int a[200'010];

int idx(int i) { return (st+i-1+n) % n; }
void shift(int s) { st = (st + s + n) % n; }
void print() {
    int cur = st;
    for (int i = 0; i < n; i++) {
        cout << a[cur] << ' ';
        if (++cur >= n) cur = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int j = 0; j < n; j++) cin >> a[j];
    while (q--) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> i >> x;
            a[idx(i)] += x;
        }
        else {
            cin >> sh;
            shift(cmd == 3 ? sh : -sh);
        }
    }
    print();
}