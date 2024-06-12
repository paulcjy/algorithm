#include <bits/stdc++.h>

using namespace std;

int n, k1, k2, p, q;
int arr[502];
int check[502];
deque<int> dq;

void shiftLeft(int k) {
    while (k--) {
        dq.push_back(dq.front());
        dq.pop_front();
    }
}

void revDq(int p, int q) {
    reverse(dq.begin()+p-1, dq.begin()+q);
}

void printDq() {
    for (int i = 0; i < n; i++)
        cout << dq[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
    for (int i = 0; i < n; i++)
        dq.push_back(i+1);

    int zero = 0;
    for (int i = 0; i < n; i++) {
        int next = (i == n-1) ? 0 : i+1;
        int prev = (i == 0) ? n-1 : i-1;
        if (arr[next] == arr[i] + 1 || (arr[i] == n && arr[next] == 1))
            check[i] = 1;
        else if (arr[prev] + 1 == arr[i] || (arr[prev] == n && arr[i] == 1))
            check[i] = 1;
        else {
            check[i] = 0;
            zero++;
        }
    }
    for (int i = 0; i < n; i++) {
        int prev = (i == 0) ? n-1 : i-1;
        if (check[prev] == 1 && check[i] == 0) p = i;
    }
    q = (p + zero - 1) % n;

    if (zero == n) {
        k2 = 1;
        while (arr[n-1-k2] - 1 <= 0) k2++;
        k1 = arr[n-1-k2] - 1;
        p = 1;
        q = n;
    }
    else {
        int first;
        if (p > q) {
            k2 = n - p;
            first = zero - 1 - k2;
            if (first <= 0) first += n;
            k1 = arr[first] - 1;
        }
        else if (q + 1 == n) {
            k2 = zero;
            first = zero - 1 - k2;
            if (first <= 0) first += n;
            k1 = arr[first] - 1;
        }
        else {
            k2 = 1;
            first = n - 1;
            k1 = arr[first] - 1;
            if (k1 <= 0) {
                k2 = n - 1;
                k1 = 2;
            }
        }
        p = (p + k2) % n + 1 ;
        q = (q + k2) % n + 1;

    }
    if (k1 < 1 || k1 >= n || k2 < 1 || k2 >= n || p < 1 || p > n || q < 1 || q > n)
        cout << "error\n";
    cout << k1 << '\n' << p << ' ' << q << '\n' << k2 << '\n';

    // printDq();
    // shiftLeft(k1);
    // printDq();
    // revDq(p, q);
    // printDq();
    // shiftLeft(k2);
    // printDq();
}