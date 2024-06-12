#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, m, ans;
int w[1005];
int f[1005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) {
        int ff; cin >> ff;
        f[ff] = 1;
    }
    for (int i = 0; i < m; i++)
        if (!f[w[i]]) ans++;
    cout << ans;
}