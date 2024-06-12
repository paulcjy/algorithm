#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int t, h, w, ans;
char a[105][105];
int v[105][105];
bool key[26];
string k;
vector<pi2> accessible[26];
queue<pi2> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void initVar() {
    ans = 0;
    memset(v, 0, sizeof(v));
    memset(key, 0, sizeof(key));
    for (auto door : accessible) door.clear();
    while (!q.empty()) q.pop();
}

bool isEdge(int x, int y) { return x == 0 || x == h-1 || y == 0 || y == w-1; }

vi bfs() {
    bool newKey[26] = {};
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (a[nx][ny] == '*' || v[nx][ny]) continue;
            char& c = a[nx][ny];
            if (isupper(c) && !key[c - 'A']) { accessible[c - 'A'].push_back({nx, ny}); continue; }
            if (islower(c) && !key[c - 'a']) key[c - 'a'] = newKey[c - 'a'] = true;
            if (c == '$') ans++;
            q.push({nx, ny});
            v[nx][ny] = 1;
        }
    }
    vi ret;
    for (int i = 0; i < 26; i++) if (newKey[i]) ret.push_back(i);
    return ret;
}

void solve() {
    initVar();
    cin >> h >> w;
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> a[i][j];
    cin >> k;
    if (k != "0") for (auto c : k) key[c - 'a'] = true;

    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) 
        if (isEdge(i, j) && islower(a[i][j])) key[a[i][j] - 'a'] = true;
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) 
        if (isEdge(i, j) && a[i][j] != '*') {
            char& c = a[i][j];
            if (isupper(c) && !key[c - 'A']) { accessible[c - 'A'].push_back({i, j}); continue; }
            if (c == '$') ans++;
            q.push({i, j});
            v[i][j] = 1;
        }

    while (1) {
        vi newKey = bfs();
        if (newKey.empty()) break;
        for (auto i : newKey) {
            for (auto [x, y] : accessible[i]) {
                q.push({x, y});
                v[x][y] = 1;
            }
            accessible[i].clear();
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t; while (t--) solve();
}