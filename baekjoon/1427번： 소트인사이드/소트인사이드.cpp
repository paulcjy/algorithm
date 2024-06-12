#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

string n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    sort(n.begin(), n.end(), greater<char>());
    cout << n;
}