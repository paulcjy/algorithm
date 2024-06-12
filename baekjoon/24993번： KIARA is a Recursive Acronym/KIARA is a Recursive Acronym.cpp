#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
string str;
vector<string> s;
int acr[26];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        s.push_back(str);
        acr[str.front() - 'A'] = 1;
    }
    for (auto& word : s) {
        bool isAcr = true;
        for (auto& c : word) if (!acr[c - 'A']) { isAcr = false; break; }
        if (isAcr) { cout << 'Y'; return 0; }
    }
    cout << 'N';
}