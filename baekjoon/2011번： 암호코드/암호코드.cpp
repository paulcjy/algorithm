#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;
#define MOD 1'000'000

string code;
int d[5005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> code;
    int n = code.size();
    if (n == 1) { 
        cout << (code[0] == '0' ? 0 : 1);
        return 0; 
    }

    d[0] = 1;
    if (code[1] != '0') d[1] = d[0];
    int ft = stoi(code.substr(0, 2));
    if (ft < 10) { cout << 0; return 0; }
    if (ft < 27) d[1]++;

    for (int i = 2; i < n; i++) {
        if (code[i] != '0') d[i] += d[i-1];
        int t = stoi(code.substr(i-1, 2));
        if (10 <= t && t <= 26) d[i] += d[i-2];
        d[i] %= MOD;
    }
    cout << d[n - 1];
}