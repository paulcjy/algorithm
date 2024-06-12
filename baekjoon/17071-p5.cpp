#include <bits/stdc++.h>

using namespace std;

int S[500001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(S, -1, sizeof(S));

    int n, k;
    cin >> n >> k;

    int move = 2;
    vector<pair<int, int>> v;
    v.push_back({k++, 0});
    while (k <= 500000) {
        v.push_back({k, v.back().second + 1});
        k += move++;
    }

    queue<int> q;
    q.push(n);
    S[n] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next : {cur - 1, cur + 1, cur * 2}) {
            if (next < 0 || next > 500000) continue;
            if (S[next] != -1) continue;
            q.push(next);
            S[next] = S[cur] + 1;
        }
    }

    // for (int i = 0; i < 40; i++) {
    //     cout << i << ' ' << S[i] << '\n';
    // }

    for (auto p : v) {
        // cout << p.first << ' ' << p.second << '\n';
        if (S[p.first] == p.second) {
            cout << p.second;
            return 0;
        }
    }
    cout << -1;

    return 0;
}