#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, input, zero, ans;
vi pos;
vi neg;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input == 0) zero++;
        else if (input > 0) pos.push_back(input);
        else if (input < 0) neg.push_back(input);
    }
    sort(pos.begin(), pos.end(), greater<>());
    sort(neg.begin(), neg.end());

    for (int i = 0; i < pos.size(); i++) {
        if (i+1 < pos.size() && pos[i+1] > 1) { ans += pos[i] * pos[i+1]; i++; }
        else ans += pos[i];
    }
    for (int i = 0; i < neg.size(); i++) {
        if (i+1 < neg.size()) { ans += neg[i] * neg[i+1]; i++; }
        else if (!zero) ans += neg[i];
    }
    cout << ans;
}