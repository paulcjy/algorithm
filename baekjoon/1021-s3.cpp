#include <bits/stdc++.h>

using namespace std;

deque<int> d;
int n, m, t, idx, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while (n) d.push_front(n--);

    while (m--) {
        cin >> t;
        idx = find(d.begin(), d.end(), t) - d.begin();
        int left = idx;
        int right = d.size() - idx;
        if (left < right) {
            ans += left;
            while (left--) {
                d.push_back(d.front());
                d.pop_front();
            }
        }
        else {
            ans += right;
            while (right--) {
                d.push_front(d.back());
                d.pop_back();
            }
        }
        d.pop_front();
    }
    cout << ans;
    return 0;
}