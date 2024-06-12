#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, len;
int a[1000005];
int d[1000005];
int lis[1000005];
int lisIdx[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(d, d+n, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int pos = lower_bound(lis, lis+len, a[i]) - lis;
        lis[pos] = a[i];
        lisIdx[pos] = i;
        if (pos > 0) d[i] = lisIdx[pos-1];
        if (pos == len) len++;
    }
    cout << len << '\n';
    stack<int> s;
    int idx = lisIdx[len-1];
    s.push(idx);
    while (d[idx] != -1) {
        s.push(d[idx]);
        idx = d[idx];
    }
    while (!s.empty()) {
        cout << a[s.top()] << ' ';
        s.pop();
    }
}