#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int n;
ll b;

vvi newMatrix(int n) { return vvi(n, vi(n, 0)); }

vvi mulMatrix(vvi a, vvi b) {
    vvi ret = newMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) 
                ret[i][j] += a[i][k] * b[k][j];
            ret[i][j] %= 1000;
        }
    }
    return ret;
}

vvi powMatrix(vvi m, ll b) {
    if (b == 1) return m;
    vvi root = powMatrix(m, b/2);
    vvi sq = mulMatrix(root, root);
    if (b & 1) return mulMatrix(m, sq);
    else return sq;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> b;
    vvi m = newMatrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];
    m = powMatrix(m, b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << m[i][j] % 1000 << ' ';
        cout << '\n';
    }
}