#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    string str;
    stack<char> s;
    char prev = 0;

    cin >> str;

    for (auto c : str) {
        if (c == '(') s.push(c);
        else {
            s.pop();
            if (prev == '(') {
                ans += s.size();
            }
            else ans++;
        }
        prev = c;
    }
    cout << ans;
    return 0;
}