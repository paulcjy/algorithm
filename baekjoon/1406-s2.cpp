#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    string s;
    int m;
    list<char> l;

    cin >> s >> m;
    
    for (auto c : s) {
        l.push_back(c);
    }
    auto cursor = l.end();

    while (m--) {
        char op;
        cin >> op;

        if (op == 'L' && cursor != l.begin()) {
            cursor--;
        }
        else if (op == 'D' && cursor != l.end()) {
            cursor++;
        }
        else if (op == 'B' && cursor != l.begin()) {
            cursor = l.erase(--cursor);
        }
        else if (op == 'P') {
            char c;
            cin >> c;
            l.insert(cursor, c);
        }
    }

    for (auto c : l) cout << c;

    return 0;
}