#include <bits/stdc++.h>

using namespace std;

enum Color {
    R = 1,
    G,
    B,
    P,
    Y
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int arr[12][6];
int prv[12][6];
int ans = 0;

bool popPuyo() {
    stack<pair<int, int>> s;
    int vis[12][6] = {};
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (arr[i][j] == 0 || vis[i][j] != 0) continue;
            int cnt = 0;
            queue<pair<int, int>> q;
            q.push({i, j});
            vis[i][j] = arr[i][j];
            s.push({i, j});
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop(); cnt++;
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
                    if (arr[nx][ny] != arr[x][y] || vis[nx][ny]) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = arr[nx][ny];
                    s.push({nx, ny});
                }
            }
            if (cnt < 4)
                while (cnt--) s.pop();
        }
    }
    if (s.size()) {
        ans++;
        while (!s.empty()) {
            auto [x, y] = s.top(); s.pop();
            arr[x][y] = 0;
        }
        return true;
    }
    else return false;
}

void pullDown() {
    for (int j = 0; j < 6; j++) {
        int idx = 11;
        int result[12] = {};
        for (int i = 11; i >= 0; i--)
            if (arr[i][j] != 0) result[idx--] = arr[i][j];
        for (int i = 0; i < 12; i++)
            arr[i][j] = result[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            char input;
            cin >> input;
            switch (input) {
                case '.':
                    arr[i][j] = 0;
                    break;
                case 'R':
                    arr[i][j] = R;
                    break;
                case 'G':
                    arr[i][j] = G;
                    break;
                case 'B':
                    arr[i][j] = B;
                    break;
                case 'P':
                    arr[i][j] = P;
                    break;
                case 'Y':
                    arr[i][j] = Y;
            }
        }
    }
    while (popPuyo()) pullDown();
    cout << ans;
}