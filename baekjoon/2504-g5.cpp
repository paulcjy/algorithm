#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    stack<char> s;
    char prev = 0;
    int ans = 0;
    int mul = 1;

    cin >> str;

    for (auto c : str) {
        if (c == '(') {
            s.push(c);
            mul *= 2;
        }
        else if (c == '[') {
            s.push(c);
            mul *= 3;
        }
        else if (c == ')') {
            if (s.empty() || s.top() != '(') {
                cout << 0;
                return 0;
            }
            if (prev == '(') ans += mul;
            s.pop();
            mul /= 2;
        }
        else if (c == ']') {
            if (s.empty() || s.top() != '[') {
                cout << 0;
                return 0;
            }
            if (prev == '[') ans += mul;
            s.pop();
            mul /= 3;
        }
        prev = c;
    }
    if (s.empty()) cout << ans;
    else cout << 0;
    return 0;
}