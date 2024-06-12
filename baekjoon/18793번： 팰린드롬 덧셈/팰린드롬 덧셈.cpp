#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int t, b;
string k;

bool isPal(string s) {
    for (int i = 0; i < s.size()/2; i++)
        if (s[i] != s[s.size()-1-i]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> b >> k;
        if (isPal(k)) {
            cout << k << " 0 0\n";
            continue;
        }
    }
}