#include <bits/stdc++.h>
using namespace std;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, x, y, d, g;
int board[105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> x >> y >> d >> g;
        vector<int> v;
        v.push_back(d);
        board[y][x] = 1;
        while (g--) {
            stack<int, vector<int>> s(v);
            while (!s.empty()) {
                v.push_back((s.top()+1)%4);
                s.pop();
            }
        }
        for (int i = 0; i < v.size(); i++) {
            int d = v[i];
            x += dx[d];
            y += dy[d];
            board[y][x] = 1;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (!board[i][j]) continue;
            if (board[i+1][j] && board[i][j+1] && board[i+1][j+1]) cnt++;
        }
    }
    cout << cnt;
}