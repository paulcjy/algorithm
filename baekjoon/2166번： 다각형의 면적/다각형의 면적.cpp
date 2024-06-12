#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n;
ll sum1, sum2;
double ans;

int main() {
    ll px, py, x1, y1, x, y;
    cin >> n >> x >> y;
    x1 = px = x;
    y1 = py = y;
    n--;
    while (n--) {
        cin >> x >> y;
        sum1 += px * y;
        sum2 += py * x;
        px = x;
        py = y;
    }
    sum1 += px * y1;
    sum2 += py * x1;
    printf("%.1f", abs(sum1 - sum2) * 0.5);
}