#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, k, ans;
deque<vector<int>> bowls;

void addOneFishToMin() {
    int m = 11111;
    for (auto bowl : bowls) for (auto fish : bowl) m = min(m, fish);
    for (auto& bowl : bowls) for (auto& fish : bowl) if (fish == m) fish++;
}

void rollBowlsToRight() {
    int height = 1;
    int width = 1;
    int ground = bowls.size() - width;
    while (ground >= height) {
        stack<vi> s;
        for (int i = 0; i < width; i++) {
            s.push(bowls.front());
            bowls.pop_front();
        }
        while (!s.empty()) {
            auto v = s.top(); s.pop();
            for (int i = 0; i < v.size(); i++) bowls[i].push_back(v[i]);
        }
        height == width ? height++ : width++;
        ground = bowls.size() - width;
    }
}

void adjustFish() {
    queue<ti3> q;
    for (int x = 0; x < bowls.size(); x++) {
        for (int y = 0; y < bowls[x].size(); y++) {
            vector<pi2> nxt;
            if (x+1 < bowls.size() && y < bowls[x+1].size()) nxt.push_back({x+1, y});
            if (y+1 < bowls[x].size()) nxt.push_back({x, y+1});
            for (auto [nx, ny] : nxt) {
                int d = (bowls[x][y] - bowls[nx][ny]) / 5;
                if (d) {
                    q.push({x, y, -d});
                    q.push({nx, ny, d});
                }
            }
        }
    }
    while (!q.empty()) {
        auto [x, y, d] = q.front(); q.pop();
        bowls[x][y] += d;
    }
}

void alignBowls() {
    deque<vi> newBowls;
    for (auto bowl : bowls)
        for (auto fish : bowl)
            newBowls.push_back(vi({fish}));
    bowls = newBowls;
}

void foldHalfTwice() {
    int len = bowls.size();
    for (auto t : {0, 1}) {
        len /= 2;
        stack<vi> s;
        for (int i = 0; i < len; i++) {
            s.push(bowls.front());
            bowls.pop_front();
        }
        for (int i = 0; i < len; i++) {
            auto v = s.top(); s.pop();
            while (!v.empty()) {
                bowls[i].push_back(v.back());
                v.pop_back();
            }
        }
    }
}

bool isAnswer() {
    int M = 0;
    int m = INT_MAX;
    for (auto bowl : bowls) {
        for (auto fish : bowl) {
            M = max(M, fish);
            m = min(m, fish);
        }
    }
    return M - m <= k;
}

void solve() {
    addOneFishToMin();
    rollBowlsToRight();
    adjustFish();
    alignBowls();
    foldHalfTwice();
    adjustFish();
    alignBowls();
    ans++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int fish; cin >> fish;
        bowls.push_back(vi({fish}));
    }

    while (!isAnswer()) solve();
    cout << ans;
}