#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

string s;
stack<string> context;

pair<bool, int> parse(int p) {
    pair<bool, int> invalid = { false, s.size() };
    if (p + 1 == s.size()) return invalid;

    // parse tag
    if (s[p] == '<') {
        for (int i = p+1, len = 0; i < s.size(); i++, len++) {
            char c = s[i];
            if (c == '>') {
                string tag = s.substr(p+1, len);
                pair<bool, int> valid = { true, i };
                if (tag.empty()) break;
                if (tag.front() == '/' && tag.back() == '/') break;
                if (tag.back() == '/') return valid;
                else if (tag.front() == '/') {
                    if (!context.empty() && context.top() == tag.substr(1)) {
                        context.pop();
                        return valid;
                    }
                    break;
                }
                else {
                    context.push(tag);
                    return valid;
                }
                break;
            }
            else if (c == '/') {
                if (i == p+1) continue;
                if (i+1 < s.size() && s[i+1] == '>') continue;
                break;
            }
            else if (isdigit(c) || islower(c)) continue;
            break;
        }
    }
    // parse symbol
    else if (s[p] == '&') {
        for (int i = p+1, len = 0; i < s.size(); i++, len++) {
            char c = s[i];
            if (c == ';') {
                string sym = s.substr(p+1, len);
                pair<bool, int> valid = { true, i };
                if (sym.size() < 2) break;
                if (sym == "lt" || sym == "gt" || sym == "amp") return valid;
                else if (sym.front() == 'x') {
                    if (!(sym.size() & 1)) break;
                    for (int j = 1; j < sym.size(); j++) {
                        char sc = sym[j];
                        if ( !( isdigit(sc) || ( 'A' <= sc && sc <= 'F' ) || ( 'a' <= sc && sc <= 'f' ) ) ) return invalid;
                    }
                    return valid;
                }
                break;
            }
            else if (isdigit(c) || isalpha(c)) continue;
            break;
        }
    }
    return invalid;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (getline(cin, s)) {
        if (!s.size()) { cout << "valid\n"; continue; }
        bool isValid = true;
        while (!context.empty()) context.pop();
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '>' || c < (char)32) isValid = false;
            else if (c == '<' || c == '&') tie(isValid, i) = parse(i);
            if (!isValid) break;
        }
        if (!context.empty()) isValid = false;
        cout << (isValid ? "valid" : "invalid") << '\n';
    }
}