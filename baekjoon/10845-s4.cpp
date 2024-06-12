#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    queue<int> q;

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int input;
            cin >> input;
            q.push(input);
        }
        else if (cmd == "pop") {
            if (q.empty()) cout << -1;
            else {
                cout << q.front();
                q.pop();
            }
        }
        else if (cmd == "size") {
            cout << q.size();
        }
        else if (cmd == "empty") {
            if (q.empty()) cout << 1;
            else cout << 0;
        }
        else if (cmd == "front") {
            if (!q.empty()) cout << q.front();
            else cout << -1;
        }
        else if (cmd == "back") {
            if (!q.empty()) cout << q.back();
            else cout << -1;
        }
        
        if (cmd != "push")
            cout << '\n';
    }
}