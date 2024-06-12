#include <bits/stdc++.h>
using namespace std;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, l, ans;
int arr[102][102];

int checkRoad(int k, int isRow) {
    int road[102];
    int isRoad = 0;
    if (isRow)
        for (int i = 0; i < n; i++)
            road[i] = arr[k][i];
    else
        for (int i = 0; i < n; i++)
            road[i] = arr[i][k];

    int dp[102];
    int prv = 0;
    for (int i = 0; i < n; i++) {
        if (road[i] == prv) dp[i] = dp[i-1] + 1;
        else dp[i] = 1;
        prv = road[i];
    }

    prv = road[0];
    for (int i = 1; i < n; i++) {
        if (prv == road[i]) continue;
        else if (abs(road[i] - prv) > 1) return 0;
        else if (prv + 1 == road[i] && dp[i-1] < l) return 0;
        else if (prv - 1 == road[i]) {
            int idx = i + l - 1;
            if (idx >= n || dp[idx] < l) return 0;
            dp[idx] = 0;
            while (idx + 1 < n && road[idx] == road[idx+1])
                dp[idx] = dp[idx++] + 1;
        }
        prv = road[i];
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    for (int i = 0; i < n; i++)
        ans += checkRoad(i, 1) + checkRoad(i, 0);
    cout << ans;
}