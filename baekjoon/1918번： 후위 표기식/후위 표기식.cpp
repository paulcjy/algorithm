#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string expr;
    stack<char> s;
    map<char, int> pri;

    char op[6] = {'+', '-', '*', '/', '(', ')'};
    int p[6] = {1, 1, 2, 2, 0, 0};
    for (int i = 0; i < 6; i++) pri[op[i]] = p[i];

    cin >> expr;
    for (auto c : expr) {
        if ('A' <= c && c <= 'Z') cout << c;
        else if (s.empty() || (s.top() == '(' && c != ')') || c == '(') s.push(c);
        else if (c == ')') {
            while (s.top() != '(') { cout << s.top(); s.pop(); }
            s.pop();
        }
        else if (pri[c] > pri[s.top()]) s.push(c);
        else {
            while (!s.empty() && pri[c] <= pri[s.top()]) { cout << s.top(); s.pop(); }
            s.push(c);
        }
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}