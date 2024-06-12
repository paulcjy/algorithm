#include <bits/stdc++.h>

using namespace std;

int arr[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int f, s, g, u, d, arrive = 0;
    cin>>f>>s>>g>>u>>d;
    memset(arr, -1, sizeof(arr));
    
    queue<int> q;
    q.push(s);
    arr[s] = 0;
    while (!q.empty()) {
        int c = q.front(); q.pop();
        if (c == g) {
            arrive = 1;
            break;
        }
        for (int next : {c+u, c-d}) {
            if (next < 1 || next > f) continue;
            if (arr[next] != -1) continue;
            q.push(next);
            arr[next] = arr[c] + 1;
        }
    }
    if (arrive)
        cout << arr[g];
    else
        cout << "use the stairs";
    return 0;
}