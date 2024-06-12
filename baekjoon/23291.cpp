#include <bits/stdc++.h>
using namespace std;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, k, ans;
deque<vector<int>> fish;

// 1. 최솟값 += 1 (복수 가능)
// 2. 왼쪽부터 어항 쌓기
// 3. 조절
// 4. 일렬로 정렬
// 5. 어항 반 접기 두 번
// 6. 조절
// 7. 일렬로 정렬
// 8. 최대-최소 차가 K 이하인지 확인

void printFish() {
    for (auto v : fish) {
        for (auto f : v) cout << f << ' ';
        cout << '\n';
    }
    cout << '\n';
}

void addFish() {
    int m = 11111;
    for (int i = 0; i < fish.size(); i++)
        m = min(m, fish[i][0]);
    for (int i = 0; i < fish.size(); i++)
        if (fish[i][0] == m) fish[i][0]++;
}

void stackLeft() {
    fish[1].push_back(fish[0][0]);
    fish.pop_front();
    int h = 2, l = 1, ground = fish.size() - l;
    while (ground >= h) {
        stack<vector<int>> s;
        while (fish.front().size() > 1) {
            s.push(fish.front());
            fish.pop_front();
        }
        while (!s.empty()) {
            auto v = s.top(); s.pop();
            for (int i = 0; i < v.size(); i++)
                fish[i].push_back(v[i]);
        }
        h = fish.front().size();
        l = 0;
        while (l < fish.size() && fish[l].size() > 1) l++;
        ground = fish.size() - l;
    }
}

void adjustFish() {
    queue<ti3> q;
    for (int x = 0; x < fish.size(); x++) {
        for (int y = 0; y < fish[x].size(); y++) {
            for (auto [dx, dy] : vector<pi2>{{1, 0}, {0, 1}}) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= fish.size() || ny >= fish[x].size() || (x < fish.size()-1 && ny >= fish[x+1].size())) continue;
                int d = abs(fish[x][y] - fish[nx][ny]) / 5;
                if (d > 0) {
                    if (fish[x][y] < fish[nx][ny]) d = -d;
                    q.push({x, y, -d});
                    q.push({nx, ny, d});
                }
            }
        }
    }
    while (!q.empty()) {
        auto [x, y, d] = q.front(); q.pop();
        fish[x][y] += d;
    }
}

void alignFish() {
    deque<vector<int>> nfish;
    for (auto a : fish)
        for (auto b : a)
            nfish.push_back(vector<int>({b}));
    fish = nfish;
}

void fold() {
    int len = fish.size();
    for (int t : {0, 1}) {
        len /= 2;
        stack<vector<int>> s;
        for (int i = 0; i < len; i++) {
            s.push(fish.front());
            fish.pop_front();
        }
        for (int i = 0; i < fish.size(); i++) {
            auto v = s.top(); s.pop();
            while (!v.empty()) {
                fish[i].push_back(v.back());
                v.pop_back();
            }
        }
    }
}

bool isAnswer() {
    int M = 0;
    int m = INT_MAX;
    for (int i = 0; i < fish.size(); i++) {
        M = max(M, fish[i][0]);
        m = min(m, fish[i][0]);
    }
    return M - m <= k;
}

bool solve() {
    addFish();
    stackLeft();
    adjustFish();
    alignFish();  
    fold();
    adjustFish();
    alignFish();
    return isAnswer();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        fish.push_back(vector<int>({input}));
    }
    if (isAnswer()) {
        cout << 0;
        return 0;
    }
    do {
        ans++;
    } while (!solve());
    cout << ans;
}