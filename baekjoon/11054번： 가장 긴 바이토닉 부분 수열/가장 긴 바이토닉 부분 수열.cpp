#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
int a[1005];
int d[1005][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int *first = &d[0][0];
    int *last = first + (2 * n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    fill(first, last, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) d[i][0] = max(d[i][0], d[j][0] + 1);
            if (a[j] > a[i]) d[i][1] = max({d[i][1], d[j][0] + 1, d[j][1] + 1});
        }
    }
    cout << *max_element(first, last);
}