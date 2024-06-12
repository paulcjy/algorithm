#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

string s1, s2;
int d[1005][1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) 
        for (int j = 0; j < s2.size(); j++)
            if (s1[i] == s2[j]) d[i+1][j+1] = d[i][j] + 1;
            else d[i+1][j+1] = max(d[i][j+1], d[i+1][j]);
    cout << d[s1.size()][s2.size()];
}