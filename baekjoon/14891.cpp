#include <bits/stdc++.h>

using namespace std;

#define L first
#define R second

string wheel[4];
pair<int, int> p[4];
int k, ans = 0;

void movePointer(int n, int dir) {
    if (dir == 0) return;
    auto [l, r] = p[n];
    l = (l - dir + 8) % 8;
    r = (r - dir + 8) % 8;
    p[n] = {l, r};
}

void turn(int n, int dir) {
    int dirs[4] = {};
    dirs[n] = dir;
    int idx = n;
    while (idx > 0) {
        string cur = wheel[idx];
        string left = wheel[idx-1];
        if (cur[p[idx].L] != left[p[idx-1].R]) dirs[idx-1] = -dirs[idx];
        idx--;
    }
    idx = n;
    while (idx < 3) {
        string cur = wheel[idx];
        string right = wheel[idx+1];
        if (cur[p[idx].R] != right[p[idx+1].L]) dirs[idx+1] = -dirs[idx];
        idx++;
    }
    for (int i = 0; i < 4; i++) 
        movePointer(i, dirs[i]);
}

void printp() {
    for (int i = 0; i < 4; i++)
        cout << p[i].L << ' ' << p[i].R << '\n';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++) 
        cin >> wheel[i];
    for(auto& [l, r] : p) 
        l = 6, r = 2;
    cin >> k;
    while (k--) {
        int n, dir;
        cin >> n >> dir;
        turn(n-1, dir);
    }
    for (int i = 3; i >= 0; i--) {
        ans <<= 1;
        movePointer(i, 2);
        if (wheel[i][p[i].R] == '1')
            ans++;
    }
    cout << ans;
}