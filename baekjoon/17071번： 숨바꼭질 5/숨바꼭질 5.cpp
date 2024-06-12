#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

const int MAX = 500'000;
int vis[MAX+5][2];
int n, k, t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    memset(vis, -1, sizeof(vis));
    queue<int> q;
    q.push(n);
    vis[n][0] = 0;
    while (!q.empty()) {
        if (vis[k][t&1] != -1) { cout << t; return 0; }
        t++; k += t;
        if (k > MAX) break;
        int qs = q.size();
        while (qs--) {
            int x = q.front(); q.pop();
            for (auto nx : {2*x, x+1, x-1}) {
                if (nx < 0 || nx > MAX) continue;
                if (vis[nx][t&1] != -1) continue;
                q.push(nx);
                vis[nx][t&1] = t;
            }
        }
    }
    cout << -1;
}