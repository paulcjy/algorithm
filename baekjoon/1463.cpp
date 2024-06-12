// bfs
#include <bits/stdc++.h>
using namespace std;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int dist[1000005];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    queue<int> q;
    q.push(1);
    dist[1] = 1;
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        for (int nx : {x * 3, x * 2, x + 1}) {
            if (nx > 1000005 || dist[nx]) continue;
            q.push(nx);
            dist[nx] = dist[x] + 1;
            if (nx == n) {
                cout << dist[nx] - 1;
                return 0;
            }
        }
    }
}