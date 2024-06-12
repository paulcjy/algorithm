#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
int a[1005];
int d[1005];
int lis[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(d, d+n, 1);
    fill(lis, lis+n, -1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                lis[i] = j;
            }
        }
    }
    stack<int> ans;
    int pos = max_element(d, d+n) - d;
    cout << d[pos] << '\n';
    while (pos != -1) {
        ans.push(a[pos]);
        pos = lis[pos];
    }
    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
}