#include <iostream>
#include <string>

using namespace std;

int main() {
    int T, n;
    string str;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> n >> str;
        for (auto c : str) {
            cout << string(n, c);
        }
        cout << '\n';
    }

    return 0;
}