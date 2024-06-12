#include <bits/stdc++.h>
using namespace std;

int n;
int s[22][22], team[22], t1[12], t2[12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];
    for (int i = n>>1; i < n; i++)
        team[i] = 1;
    int m = 0x7fffffff;
    do {
        int p1 = 0, p2 = 0, s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++)
            if (team[i]) t1[p1++] = i;
            else t2[p2++] = i;
        for (int i = 0; i < (n>>1)-1; i++) {
            for (int j = i+1; j < n>>1; j++) {
                s1 += s[t1[i]][t1[j]] + s[t1[j]][t1[i]];
                s2 += s[t2[i]][t2[j]] + s[t2[j]][t2[i]];
            }
        }
        m = min(m, abs(s1 - s2));
    } while (next_permutation(team, team+n));
    cout << m;
}