#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, ans;
int t[10'005];
int d[10'005];
vi adj[10'005];
int ind[10'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cnt, j;
        cin >> t[i] >> cnt;
        while (cnt--) {
            cin >> j;
            adj[j].push_back(i);
            ind[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!ind[i]) { q.push(i); d[i] = t[i]; }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ans = max(ans, d[cur]);
        for (auto nxt : adj[cur]) {
            d[nxt] = max(d[nxt], d[cur] + t[nxt]);
            if (!--ind[nxt]) q.push(nxt);
        }
    }
    cout << ans;
}