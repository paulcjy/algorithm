#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int, int>> s;
    int n, h;
    long long ans = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h;
        if (s.empty()) s.push({h, i});
        else {
            while (!s.empty() && h >= s.top().first) {
                ans += i - s.top().second - 1;
                s.pop();
            }
            s.push({h, i});
        }
    }

    pair<int, int> last;
    last = s.top();
    s.pop();
    
    while (!s.empty()) {
        ans += last.second - s.top().second;
        s.pop();
    }

    cout << ans;

    return 0;
}