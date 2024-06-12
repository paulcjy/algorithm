#include <bits/stdc++.h>
using namespace std;

string s;
int cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for (int i = 1; i < s.size(); i++) cnt += (s[i] != s[i-1]);
    cout << (cnt + 1) / 2;
}