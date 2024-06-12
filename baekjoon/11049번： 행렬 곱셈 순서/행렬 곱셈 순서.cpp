#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, ans;
vi m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int a, b;
    cin >> a >> b;
    m.push_back(a);
    m.push_back(b);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        m.push_back(b);
    }

    while (m.size() > 3) {
        int idx = min_element(m.begin(), m.end()) - m.begin();
        cout << idx << '\n';
        if (idx < m.size() - 2) {
            ans += m[idx] * m[idx+1] * m[idx+2];
            m.erase(m.begin() + idx + 1);
        }
        else if (idx > 1) {
            ans += m[idx-2] * m[idx-1] * m[idx];
            m.erase(m.begin() + idx - 1);
        }
    }
    ans += m[0] * m[1] * m[2];
    cout << ans;
}

