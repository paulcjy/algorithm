#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int t;
string m;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> m;
        int cnt[26] = {};
        bool ok = true;
        for (int i = 0; i < m.size(); i++) {
            char& c = m[i];
            cnt[c - 'A']++;
            if (cnt[c - 'A'] == 3) {
                if (i + 1 == m.size() || m[i+1] != c) {
                    ok = false;
                    break;
                }
                if (m[i+1] == c) {
                    cnt[c - 'A'] = 0;
                    i++;
                }
            }
        }
        cout << (ok ? "OK" : "FAKE") << '\n';
    }
}