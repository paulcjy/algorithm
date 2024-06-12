#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, ans;
int s[105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = n-2; i >= 0; i--) {
        if (s[i] >= s[i+1]) {
            ans += s[i] - s[i+1] + 1;
            s[i] = s[i+1] - 1;
        }
    }
    cout << ans;
}