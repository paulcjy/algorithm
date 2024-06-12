// next permutation
#include <bits/stdc++.h>

using namespace std;

int n, m;
int num[50];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < 49; i++)
        num[i] = (i / 7) + 1;
    
    do {
        for (int i = 0; i < m; i++) 
            cout << num[i] << ' ';
        cout << '\n';
        reverse(num+(m*7), num+(n*7));
    } while (next_permutation(num, num+(n*7)));
}