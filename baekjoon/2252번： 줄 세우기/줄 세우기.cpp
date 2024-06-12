#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, m;
vi adj[32'005];
int ind[32'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ind[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) if (!ind[i]) q.push(i);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for (auto next : adj[cur]) 
            if (!(--ind[next])) q.push(next);
    }
}