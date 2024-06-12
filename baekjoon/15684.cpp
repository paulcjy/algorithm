#include <bits/stdc++.h>
using namespace std;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;
#define X first
#define Y second

int n, m, h, ans = 4, isImpossible;
int arr[35][15];
int run[35][15];
int p[310];
vector<pi2> v;
int vsize;

bool isAnswer() {
    for (int i = 1; i <= n; i++) {
        int l = i;
        for (int j = 1; j <= h; j++) {
            if (arr[j][l] == 1) l++;
            else if (arr[j][l-1] == 1) l--;
        }
        if (l != i) return false;
    }
    return true;
}

void bt(int line, int s) {
    if (isAnswer()) {
        ans = min(ans, line);
        return;
    }
    if (line == 3) return; 
    for (int i = s; i < vsize; i++) {
        arr[v[i].X][v[i].Y] = 1;
        bt(line+1, i+1);
        arr[v[i].X][v[i].Y] = 0;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;
    while (m--) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[a][b-1] = -1;
        arr[a][b+1] = -1;
    }

    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= n; j++)
            if (arr[i][j] == 0) v.push_back({i, j});
    vsize = v.size();

    bt(0, 0);
    if (ans == 4) cout << -1;
    else cout << ans;
}