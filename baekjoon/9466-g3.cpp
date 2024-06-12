#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int vis[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        cin >> n;
        fill(vis+1, vis+n+1, 0);
        for (int i = 1; i <= n; i++) 
            cin >> arr[i];
        
        for (int i = 1; i <= n; i++) {
            if (vis[i] != 0) continue;
            int cur = i;
            while (1) {
                vis[cur] = i;
                cur = arr[cur];
                if (vis[cur] == i) {
                    while (vis[cur] != -1) {
                        vis[cur] = -1;
                        cur = arr[cur];
                    }
                    break;
                }
                else if (vis[cur] != 0) break;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (vis[i] != -1) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}