#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, input;
    string cmd;
    stack<int> s;
    cin >> N;

    while (N--) {
        cin >> cmd;

        if (cmd == "push") {
            cin >> input;
            s.push(input);
        }
        else if (cmd == "pop") {
            if (!s.empty()) {
                cout << s.top() << '\n';
                s.pop();
            }
            else cout << -1 << '\n';
        }
        else if (cmd == "size") {
            cout << s.size() << '\n';
        }
        else if (cmd == "empty") {
            if (s.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (cmd == "top") {
            if (s.empty()) cout << -1 << '\n';
            else cout << s.top() << '\n';
        }
    }

    return 0;
}