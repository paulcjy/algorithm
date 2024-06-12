#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, c, m, ans;
vector<ti3> info;
int truck[2'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> c >> m;
    for (int i = 0; i < m; i++)  {
        int s, d, box;
        cin >> s >> d >> box;
        info.push_back({d, s, box});
    }
    sort(info.begin(), info.end());
    
    for (auto [d, s, box] : info) {
        box = min(box, c - *max_element(truck+s, truck+d));
        if (box > 0) {
            ans += box;
            for (int i = s; i < d; i++) truck[i] += box;
        }
    }
    cout << ans;
}