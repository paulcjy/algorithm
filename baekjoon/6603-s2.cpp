#include <bits/stdc++.h>

using namespace std;

int num[15];
int p[15];
int k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> k;
        if (k == 0) break;
        for (int i = 6; i < k; i++)
            p[i] = 1;
        for (int i = 0; i < k; i++)
            cin >> num[i];
        do {
            for (int i = 0; i < k; i++) 
                if (p[i] == 0) cout << num[i] << ' ';
            cout << '\n';
        } while (next_permutation(p, p+k));
        cout << '\n';
    }
}