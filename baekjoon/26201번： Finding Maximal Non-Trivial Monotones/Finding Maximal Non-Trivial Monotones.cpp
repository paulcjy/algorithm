#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, ans, cnt;
string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;
    for (auto c : s) {
        if (c == 'a') cnt++;
        else {
            if (cnt > 1) ans += cnt;
            cnt = 0;
        }
    }
    if (cnt > 1) ans += cnt;
    cout << ans;
}