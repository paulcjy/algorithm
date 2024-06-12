#include <bits/stdc++.h>

using namespace std;

int c[2][1001], a, b, n = 3;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (n--) {
        cin >> a >> b;
        c[0][a]++;
        c[1][b]++;
    }
    
    for (int i = 0; i < 1001; i++) {
        if (c[0][i] == 1) a = i;
        if (c[1][i] == 1) b = i;
    }
    
    cout << a << ' ' << b;    
}