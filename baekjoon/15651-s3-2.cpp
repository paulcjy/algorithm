#include <bits/stdc++.h>

using namespace std;

int arr[50];
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            arr[i*m+j] = i+1;
    do {
        for (int i = 0; i < m; i++) 
            cout << arr[i] << ' ';
        cout << '\n';
        reverse(arr+m, arr+(n*m));
    } while (next_permutation(arr, arr+(n*m)));
}