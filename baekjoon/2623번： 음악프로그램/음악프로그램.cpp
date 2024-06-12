#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, m;
vi adj[1005];
int ind[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (m--) {
        int cnt; cin >> cnt;
        if (cnt <= 1) continue;
        vi order;
        while (cnt--) {
            int cur; cin >> cur;
            order.push_back(cur);
        }
        for (int i = 1; i < order.size(); i++) {
            int prv = order[i-1];
            int cur = order[i];
            adj[prv].push_back(cur);
            ind[cur]++;
        }
    }
    
    queue<int> q;
    vi ans;
    for (int i = 1; i <= n; i++) if (!ind[i]) q.push(i);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for (auto nxt : adj[cur])
            if (!--ind[nxt]) q.push(nxt);
    }
    if (ans.size() != n) cout << 0;
    else for (auto i : ans) cout << i << '\n';
}