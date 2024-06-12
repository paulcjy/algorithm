#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

string s;
bool show[105];

void solve(int st, int en) {
    int m = st;
    for (int i = st; i < en; i++)
        if (s[m] > s[i]) m = i;
    show[m] = true;
    for (int i = 0; i < s.size(); i++)
        if (show[i]) cout << s[i];
    cout << '\n';
    if (m + 1 < en) solve(m+1, en);
    if (m > st) solve(st, m);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    solve(0, s.size());
}