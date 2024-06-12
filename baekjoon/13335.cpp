#include <bits/stdc++.h>

using namespace std;

int N, W, L;
int idx, t = 0, weight;
int truck[1002];
queue<pair<int, int>> bridge; // {트럭 번호, 다리에 올라간 시간}

void pushBr() {
    if (idx == N) return;
    bridge.push({idx, t});
    weight += truck[idx];
    idx++;
}

int pullBr() {
    auto [I, T] = bridge.front(); bridge.pop();
    weight -= truck[I];
    return T;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> W >> L;
    for (int i = 0; i < N; i++)
        cin >> truck[i];
    
    do {
        t++;
        if (weight + truck[idx] > L)
            t = bridge.front().second + W;
        if (!bridge.empty() && t == bridge.front().second + W)
            pullBr();
        if (weight + truck[idx] <= L)
            pushBr();
    } while (!bridge.empty());
    cout << t;
}