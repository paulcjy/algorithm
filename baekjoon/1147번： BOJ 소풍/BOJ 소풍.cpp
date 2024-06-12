#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, m, ans, tmp;
vector<pi2> sqsum[20010];

void fillsq() {
    for (int a = 0; a <= 100; a++) {
        for (int b = a; b <= 100; b++) {
            sqsum[a*a + b*b].push_back({a, b});
        }
    }
}

int countsq(int a, int b) {
    if (a > n || b > m) return 0;
    int ret = (n - a + 1) * (m - b + 1);
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    fillsq();
    int& big = n > m ? n : m;
    int len = big * big + 1;
    for (int t = 1; t < len; t++) {
        auto& v = sqsum[t];
        for (int i = 0; i < v.size(); i++) {
            auto [a, b] = v[i];
            for (int j = i; j < v.size(); j++) {
                auto [p, q] = v[j];
                int sum = 0;
                if (a == 0) {
                    if (p == 0) ans += countsq(b, b);
                    else { 
                        sum += countsq(p, q+b);
                        sum += countsq(q, p+b);
                        sum += countsq(p+b, q);
                        sum += countsq(q+b, p);
                        ans += (sum << 1);
                    }
                }
                else if (a != b) {
                    if (p != q) {
                        if (i == j) { 
                            ans += (countsq(a+b, a+b) << 2);
                            ans += countsq(2*a, 2*b);
                            ans += countsq(2*b, 2*a);
                        }
                        else {
                            sum += countsq(a+p, b+q);
                            sum += countsq(a+q, b+p);
                            sum += countsq(b+p, a+q);
                            sum += countsq(b+q, a+p);
                            ans += (sum << 2);
                        }
                    }
                    else {
                        sum += countsq(a+p, b+p);
                        sum += countsq(b+p, a+p);
                        ans += (sum << 2);
                    }
                }
                else ans += countsq(2*a, 2*a);
            }
        }
    }
    cout << ans;
}