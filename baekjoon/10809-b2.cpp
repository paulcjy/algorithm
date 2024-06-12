#include <iostream>
#include <string>
#include <algorithm>


using namespace std;
int main() {
    string str;
    int alpha[26];
    
    fill_n(alpha, 26, -1);
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (alpha[str[i] - 'a'] == -1) {
            alpha[str[i] - 'a'] = i;
        }
    }

    for (auto n : alpha) cout << n << ' ';

    return 0;
}