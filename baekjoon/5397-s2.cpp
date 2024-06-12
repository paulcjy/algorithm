#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        list<char> pwd;
        auto p = pwd.begin();

        cin >> s;

        for (auto c : s) {
            if (c == '<' && p != pwd.begin()) p--;
            else if (c == '>' && p != pwd.end()) p++;
            else if (c == '-' && p != pwd.begin()) p = pwd.erase(--p);
            else if (isalpha(c) || isdigit(c)) pwd.insert(p, c);
        }
        
        for (auto c : pwd) cout << c;
        cout << '\n';
    }

    return 0;
}