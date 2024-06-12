#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int g, p, limit, ans;
int plane[100'005];
int isUsed[100'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> g >> p;
    for (int i = 0; i < p; i++) {
        cin >> limit;
        int gate = limit;
        if (plane[limit]) gate = plane[limit] - 1;
        while (gate > 0 && isUsed[gate]) gate--;
        if (gate == 0) break;
        isUsed[gate] = true;
        plane[limit] = gate;
        ans++;
    }
    cout << ans;
}