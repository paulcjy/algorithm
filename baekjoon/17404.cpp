#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;
#define X first
#define Y second
#define INF 10'000'000

int n;
int cost[1005][3];
int d[1005][3];
int m = INF;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> cost[i][j];
    for (int first = 0; first < 3; first++) {
        int a = (first + 1) % 3;
        int b = (first + 2) % 3;
        memset(d, 0, sizeof(d));
        d[0][first] = cost[0][first];
        d[0][a] = INF;
        d[0][b] = INF;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                int p = (j + 1) % 3;
                int q = (j + 2) % 3;
                d[i][j] = min(d[i-1][p], d[i-1][q]) + cost[i][j];
            }
        }
        m = min({m, d[n-1][a], d[n-1][b]});
    }
    cout << m;
}