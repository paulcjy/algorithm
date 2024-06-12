#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;
#define INF INT_MAX

int n, k, ans;
int order[105];
bool plug[105];
int d[105];
int tmp[105];
vector<pi2> plugged; // {다음에 나오는 거리, 전자제품 번호}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> order[i];
    fill_n(tmp, k+1, -1);
    for (int i = 0; i < k; i++) {
        int cur = order[i];
        if (tmp[cur] == -1) tmp[cur] = i; 
        else {
            d[tmp[cur]] = i;
            tmp[cur] = i;
        }
    }
    for (int i = 0; i < k; i++) {
        int cur = order[i];
        int next = d[i] ? d[i] : INF;
        if (plug[cur]) (*find_if(plugged.begin(), plugged.end(), [cur](pi2 e) { return e.second == cur; })).first = next;
        else {
            if (plugged.size() == n) {
                sort(plugged.begin(), plugged.end());
                auto [_, unplugged] = plugged.back(); plugged.pop_back();
                plug[unplugged] = false;
                ans++;
            }
            plug[cur] = true;
            plugged.push_back({next, cur});
        }
    }
    cout << ans;
}