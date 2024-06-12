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
            bool paste = 0;
            for (int i = 0; i < n-r+1; i++) {
                for (int j = 0; j < m-c+1; j++) {
                    bool crash = 0;
                    for (int x = i; x < i+r; x++) {
                        for (int y = j; y < j+c; y++) {
                            if (laptop[x][y] == 1 && sticker[x-i][y-j] == 1) {
                                crash = 1;
                                break;
                            }
                        }
                        if (crash) break;
                    }
                    if (!crash) {
                        paste = 1;
                        for (int x = i; x < i+r; x++) 
                            for (int y = j; y < j+c; y++) 
                                if (sticker[x-i][y-j])
                                    laptop[x][y] = 1;
                    }
                    if (paste) break;
                }
                if (paste) break;
            }
            if (paste) break;
            rotate();
        }
    }
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (laptop[i][j]) ans++;
    cout << ans;
}