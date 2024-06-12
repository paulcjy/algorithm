#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int t, w;
int d[1005][35];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> w;
    while (t--) {
        int tree;
        cin >> tree;
        for (int i = 0; i <= w; i++)
            if (i == 0) d[t][i] = d[t+1][i] + (i%2 + 1 == tree);
            else d[t][i] = max(d[t+1][i], d[t+1][i-1]) + (i%2 + 1 == tree);
    }
    cout << *max_element(d[0], d[0] + w+1);
}