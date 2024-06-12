#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, ans;
vector<pi2> room;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        room.push_back({e, s});
    }
    sort(room.begin(), room.end());
    int last = 0;
    for (auto [e, s] : room) {
        if (s >= last) {
            ans++;
            last = e;
        }
    }
    cout << ans;
}