#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, len, input;
int lis[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        int pos = lower_bound(lis, lis+len, input) - lis;
        lis[pos] = input;
        if (pos == len) len++;
    }
    cout << len;
}