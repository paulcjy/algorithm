#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int pos = 0;
    int len = 0;
    int ans = 0;
    int minus = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            int n = stoi(s.substr(pos, len));
            ans += n * minus;
            pos = i + 1;
            len = 0;
            if (s[i] == '-') minus = -1;
        }
        else len++;
    }
    ans += minus * stoi(s.substr(pos, len));
    cout << ans;
}