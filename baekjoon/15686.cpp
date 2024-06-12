#include <bits/stdc++.h>

using namespace std;

int n, m, ans = 0x7fffffff;
int p[15];
vector<pair<int, int>> H;
vector<pair<int, int>> C;

int distance(pair<int, int> p1, pair<int, int> p2) {
    auto [a, b] = p1;
    auto [x, y] = p2;
    a = a > x ? a - x : x - a;
    b = b > y ? b - y : y - b;
    return a + b;
}

int chicken() {
    int sum = 0;
    for (auto h : H) {
        int mn = 100;
        for (int i = 0; i < C.size(); i++) {
            if (p[i]) continue;
            mn = min(mn, distance(h, C[i]));
        }
        sum += mn;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            if (input == 1)
                H.push_back({i, j});
            else if (input == 2)
                C.push_back({i, j});
        }
    }
    for (int i = m; i < C.size(); i++)
        p[i] = 1;
    do {
        ans = min(ans, chicken());
    } while (next_permutation(p, p+C.size()));
    cout << ans;
}