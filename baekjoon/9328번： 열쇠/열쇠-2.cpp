#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int t, h, w, ans;
char a[105][105];
bool v[105][105];
bool key[30];
string givenKey;
vector<pi2> acc[30];
queue<pi2> q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isEdge(int x, int y) { return x == 0 || x == h-1 || y == 0 || y == w-1; }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) {
        ans = 0;
        memset(v, 0, sizeof(v));
        memset(key, 0, sizeof(key));
        for (auto& doors : acc) doors.clear();
        while (!q.empty()) q.pop();

        cin >> h >> w;
        for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++) cin >> a[i][j];
        for (int i = 0; i <= w+1; i++) { a[0][i] = '.'; a[h+1][i] = '.'; }
        for (int i = 1; i <= h; i++) { a[i][0] = '.'; a[i][w+1] = '.'; }
        cin >> givenKey;
        for (auto k : givenKey) key[k - 'a'] = true;

        q.push({0, 0});
        v[0][0] = 1;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (a[x][y] == '$') ans++;
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= h+2 || ny >= w+2) continue;
                char& c = a[nx][ny];
                if (c == '*' || v[nx][ny]) continue;
                if (isupper(c) && !key[c - 'A']) {
                    acc[c - 'A'].push_back({nx, ny});
                    continue;
                }
                if (islower(c) && !key[c - 'a']) {
                    key[c - 'a'] = true;
                    for (auto door : acc[c - 'a']) q.push(door);
                    acc[c - 'a'].clear();
                }
                q.push({nx, ny});
                v[nx][ny] = 1;
            }
        }
        cout << ans << '\n';
    }
}