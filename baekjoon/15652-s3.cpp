#include <bits/stdc++.h>

using namespace std;

int num[70];
int p[70];
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            num[i*m+j] = i+1;
    for (int i = m; i < n*m; i++)
        p[i] = 1;

    vector<int> prev;
    do {
        vector<int> cur;
        for (int i = 0; i < n*m; i++) 
            if (p[i] == 0) cur.push_back(num[i]);
        if (cur == prev) continue;
        for (auto i : cur) cout << i << ' ';
        cout << '\n';
        prev.swap(cur);
    } while (next_permutation(p, p+n*m));


}