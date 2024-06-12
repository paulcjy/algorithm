#include <bits/stdc++.h>

using namespace std;

stack<pair<int, int>> s;
int n, a, ans[1000000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (s.empty()) s.push({a, i});
        else {
            while (!s.empty() && a > s.top().first) {
                ans[s.top().second] = a;
                s.pop();
            }
            s.push({a, i});
        }
    }

    for (int i = 0; i < n; i++) 
        if (ans[i])
            cout << ans[i] << ' ';
        else
            cout << -1 << ' ';
    return 0;
}