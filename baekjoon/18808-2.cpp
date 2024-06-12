#include <bits/stdc++.h>

using namespace std;

int n, m, k, ans = 0;
int laptop[42][42];
int r, c;
int sticker[12][12];

void rotate() {
    int temp[12][12];
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++) 
            temp[i][j] = sticker[i][j];
    for (int i = 0; i < c; i++) 
        for (int j = 0; j < r; j++) 
            sticker[i][j] = temp[r-1-j][i];
    swap(r, c);
}

bool putable(int x, int y) {
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++) 
            if (laptop[x+i][y+j] == 1 && sticker[i][j] == 1)
                return false;
    return true;
}

void put(int x, int y) {
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++) 
            if (sticker[i][j])
                laptop[x+i][y+j] = 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    while (k--) {
        cin >> r >> c;
        for (int i = 0; i < r; i++) 
            for (int j = 0; j < c; j++) 
                cin >> sticker[i][j];
        for (int rot = 0; rot < 4; rot++) {
            bool isPut = 0;
            for (int i = 0; i < n-r+1; i++) {
                for (int j = 0; j < m-c+1; j++) {
                    if (putable(i, j)) {
                        put(i, j);
                        isPut = 1;
                        break;
                    }
                }
                if (isPut) break;
            }
            if (isPut) break;
            rotate();
        }
    }
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (laptop[i][j]) ans++;
    cout << ans;
}