#include <bits/stdc++.h>

using namespace std;

int n, h;
long long ans;
stack<pair<int, int>> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> h;
            if (s.empty()) {
                s.push({h, i});
                ans = max(ans, h);
            }
            else {
                
            }
        }
    }

    return 0;
}