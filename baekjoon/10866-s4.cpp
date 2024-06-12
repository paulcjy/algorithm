#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    deque<int> d;

    while (N--) {
        string cmd;
        int input;

        cin >> cmd;

        if (cmd == "push_front") {
            cin >> input;
            d.push_front(input);
        }
        else if (cmd == "push_back") {
            cin >> input;
            d.push_back(input);
        }
        else if (cmd == "pop_front") {
            if (!d.empty()) {
                cout << d.front() << '\n';
                d.pop_front();
            }
            else cout << -1 << '\n';
        }
        else if (cmd == "pop_back") {
            if (!d.empty()) {
                cout << d.back() << '\n';
                d.pop_back();
            }
            else cout << -1 << '\n';
        }
        else if (cmd == "size") {
            cout << d.size() << '\n';
        }
        else if (cmd == "empty") {
            if (d.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (cmd == "front") {
            if (!d.empty()) cout << d.front() << '\n';
            else cout << -1 << '\n';
        }
        else if (cmd == "back") {
            if (!d.empty()) cout << d.back() << '\n';
            else cout << -1 << '\n';
        }
    }

    return 0;
}