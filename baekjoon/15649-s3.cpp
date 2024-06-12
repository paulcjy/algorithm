// next permutation
#include <bits/stdc++.h>

using namespace std;

int n, m;
int p[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    do {
        for (int i = 0; i < m; i++)
            cout << p[i] << ' ';
        cout << '\n';
        reverse(p+m, p+n);
    } while (next_permutation(p, p+n));
}