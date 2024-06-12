// next permutation
#include <bits/stdc++.h>

using namespace std;

int num[8];
int p[8];
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    iota(num, num+n, 1);
    for (int i = m; i < n; i++)
        p[i] = 1;

    do {
        for (int i = 0; i < n; i++)
            if (p[i] == 0)
                cout << num[i] << ' ';
        cout << '\n';
    } while (next_permutation(p, p+n));
}