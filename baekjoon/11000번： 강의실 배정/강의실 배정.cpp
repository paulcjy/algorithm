#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;
#define X first
#define Y second

int n, ans;
pi2 cl[200'005];
priority_queue<int, vector<int>, greater<int>> room;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> cl[i].X >> cl[i].Y;
    sort(cl, cl+n);
    for (int i = 0; i < n; i++) {
        auto [s, t] = cl[i];
        if (!room.empty() && s >= room.top()) room.pop();
        room.push(t);
        ans = max(ans, (int)room.size());
    }
    cout << ans;
}