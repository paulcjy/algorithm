#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
int a[1005][1005];
int v[1005][1005];
vi groupCnt(1, 0);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char input;
            cin >> input;
            a[i][j] = input - '0';
        }
    }

    int groupNum = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] || v[i][j]) continue;
            queue<pi2> q;
            int cnt = 0;
            q.push({i, j});
            v[i][j] = groupNum;
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                cnt++;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (a[nx][ny] || v[nx][ny]) continue;
                    q.push({nx, ny});
                    v[nx][ny] = groupNum;
                }
            }
            groupCnt.push_back(cnt);
            groupNum++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!a[i][j]) continue;
            int sum = 0;
            vi sumGroup;
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                sumGroup.push_back(v[nx][ny]);
            }
            sort(sumGroup.begin(), sumGroup.end());
            sumGroup.erase(unique(sumGroup.begin(), sumGroup.end()), sumGroup.end());
            for (auto g : sumGroup) sum += groupCnt[g];
            a[i][j] = (sum + 1) % 10;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << a[i][j];
        cout << '\n';
    }
}