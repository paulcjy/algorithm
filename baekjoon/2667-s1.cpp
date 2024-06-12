#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int arr[26][26];
int vis[26][26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < n; j++) {
            arr[i][j] = input[j] - '0';
        }
    }
    
    int cnt = 0;
    queue<pair<int, int>> q;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0 || vis[i][j]) continue;
            int area = 0;
            q.push({i, j});
            vis[i][j] = 1;
            while (!q.empty()) {
                auto c = q.front(); q.pop();
                area++;
                for (int d = 0; d < 4; d++) {
                    int nx = c.X + dx[d];
                    int ny = c.Y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (arr[nx][ny] == 0 || vis[nx][ny]) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            cnt++;
            v.push_back(area);
        }
    }
    cout << cnt << '\n';
    sort(v.begin(), v.end());
    for (auto area : v)
        cout << area << '\n';
    return 0;
}