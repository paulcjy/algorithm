#include <bits/stdc++.h>

using namespace std;

int n, t, x, y;
int b[6][4];
int g[6][4];
int score = 0;

void putBlock(int (&a)[6][4], int t, int y) {
    if (t == 1 || t == 3) {
        for (int i = 0; i <= 6; i++) {
            if (i == 6 || a[i][y] != 0) {
                a[i-1][y] = 1;
                if (t == 3) a[i-2][y] = 1;
                break;
            }
        }
    }
    else if (t == 2) {
        for (int i = 0; i <= 6; i++) {
            if (i == 6 || a[i][y] != 0 || a[i][y+1] != 0) {
                a[i-1][y] = 2;
                a[i-1][y+1] = 3;
                break;
            }
        }
    }
}

bool popFull(int (&a)[6][4]) {
    int r = -1;
    for (int i = 0; i < 6; i++) {
        if (a[i][0] && a[i][1] && a[i][2] && a[i][3]) {
            score++;
            r = i;
            for (int j = 0; j < 4; j++)
                a[i][j] = 0;
        }
    }
    if (r != -1){
        int tmp[6][4] = {};
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < 4; j++) {
                tmp[i][j] = a[i][j];
                a[i][j] = 0;
            }
        }
        for (int i = r-1; i >= 0; i--) {
            for (int j = 0; j < 4; j++) {
                if (tmp[i][j] == 0 || tmp[i][j] == 3) continue;
                if (tmp[i][j] == 1) putBlock(a, 1, j);
                else putBlock(a, 2, j);
            }
        }
    }
    return (r != -1);
}

void pushSpecial(int (&a)[6][4]) {
    int cnt = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
            if (a[i][j]) { cnt++; break; }
    if (cnt)
        for (int j = 0; j < 4; j++)
            for (int i = 5 - cnt; i >= 0; i--) {
                a[i+cnt][j] = a[i][j];
                a[i][j] = 0;
            }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> t >> x >> y;
        putBlock(g, t, y);
        if (t == 2 || t == 3) t = 5 - t;
        putBlock(b, t, x);
        while (popFull(g));
        while (popFull(b));
        pushSpecial(g);
        pushSpecial(b);
    }
    int block = 0;
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (g[i][j]) block++;
            if (b[i][j]) block++;
        }
    }
    cout << score << '\n' << block;
}