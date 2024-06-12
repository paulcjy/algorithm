#include <bits/stdc++.h>

using namespace std;

int vis[100001];
int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    fill(vis, vis+100001, -1);

    queue<int> q;
    q.push(n);
    vis[n] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int teleport = cur << 1;
        while (teleport <= 100000 && vis[teleport] == -1) {
            vis[teleport] = vis[cur];
            q.push(teleport);
            teleport <<= 1;
        }
        for (int next : {cur - 1, cur + 1}) {
            if (next < 0 || next > 100000 || vis[next] != -1) continue;
            q.push(next);
            vis[next] = vis[cur] + 1;
        }
    }
    cout << vis[k];
    return 0;
}