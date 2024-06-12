#include <bits/stdc++.h>
using namespace std;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[52][52];
int n, m, r, c, d;
int cleaned = 0;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r >> c >> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            cin >> arr[i][j];
    
    while (1) {
        if (arr[r][c] == 0) arr[r][c] = 2, cleaned++;
        int uncleaned = 0;
        for (int i = 0; i < 4; i++)
            if (arr[r+dx[i]][c+dy[i]] == 0) uncleaned++;
        if (uncleaned == 0) {
            int back = (d + 2) % 4;
            if (arr[r+dx[back]][c+dy[back]] != 1) {
                r = r + dx[back];
                c = c + dy[back];
                continue;
            }
            else break;
        }
        else {
            do {
                d = (d + 3) % 4;
            } while (arr[r+dx[d]][c+dy[d]] != 0);
            r = r + dx[d];
            c = c + dy[d];
        }
    }
    cout << cleaned;
}