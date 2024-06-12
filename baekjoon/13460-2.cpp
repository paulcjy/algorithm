#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[12][12];
int dir[10];
int n, m;
int ans = INT_MAX;
pair<int, int> R, B;

void bt(int k) {
    if (k == 10) {
        auto [rx, ry] = R;
        auto [bx, by] = B;
        bool rOut = false;
        bool bOut = false;
        int cnt = 0;
        for (int i = 0; i < 10; i++) {
            int d = dir[i];
            while (1) {
                int nrx = rx + dx[d];
                int nry = ry + dy[d];
                int nbx = bx + dx[d];
                int nby = by + dy[d];
                if (!rOut && arr[nrx][nry] == 0 && nbx == rx && nby == ry) break;
                if (!bOut && arr[nbx][nby] == 0 && nrx == bx && nry == by) break;
                if (arr[nrx][nry] == 0 && arr[nbx][nby] == 0) break;
                if (arr[nrx][nry] != 0) {rx = nrx; ry = nry;}
                if (arr[nbx][nby] != 0) {bx = nbx; by = nby;}
                if (arr[rx][ry] == -1) rOut = true;
                if (arr[bx][by] == -1) bOut = true;
            }
            if (!rOut && !bOut) continue;
            if (rOut && !bOut) cnt = i + 1;
            break;
        }
        if (cnt) ans = min(ans, cnt);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (k == 0 || dir[k-1] != i) {
            dir[k] = i;
            bt(k+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char input;
            cin >> input;
            if (input == '#') arr[i][j] = 0;
            else if (input == 'O') arr[i][j] = -1;
            else {
                if (input == 'R') R = {i, j};
                if (input == 'B') B = {i, j};
                arr[i][j] = 1;
            }
        }
    }
    bt(0);
    cout << ((ans == INT_MAX) ? -1 : ans);
}