#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int t, n, k, w;
int build[1005];
int d[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vvi adj(n+1);
        vi ind(n+1, 0);
        for (int i = 1; i <= n; i++) cin >> build[i];
        while (k--) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            ind[y]++;
        }
        cin >> w;

        queue<int> q;
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= n; i++) if (!ind[i]) q.push(i);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (cur == w) break;
            for (auto next : adj[cur]) {
                d[next] = max(d[next], d[cur] + build[cur]);
                if (!(--ind[next])) q.push(next);
            }
        }
        cout << d[w] + build[w] << '\n';
    }
}