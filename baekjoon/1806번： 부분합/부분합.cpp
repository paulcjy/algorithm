#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;
#define MAX 100000

int n, s, ans = MAX;
int a[100'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    int i = 1, j = 1, sum = 0;
    while (i <= n + 1 && j <= n) {
        if (sum < s) sum += a[i++];
        else {
            ans = min(ans, i-j);
            sum -= a[j++];
        }
    }
    cout << (ans == MAX ? 0 : ans);
}