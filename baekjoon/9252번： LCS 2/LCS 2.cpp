#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

string s1, s2;
int lcs[1005][1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i-1] == s2[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1;
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    int i = s1.size();
    int j = s2.size();
    int len = lcs[i][j];
    cout << len << '\n';
    if (len) {
        string ans = "";
        while (lcs[i][j] != 0) {
            if (lcs[i][j] == lcs[i-1][j]) i--;
            else if (lcs[i][j] == lcs[i][j-1]) j--;
            else {
                ans += s1[i-1];
                i--; j--;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
}