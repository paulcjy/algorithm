#include <bits/stdc++.h>
using namespace std;

int n, k1, k2, p, q, rs;
int zero = 0;
int arr[502];
int check[502];

void printArr() {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}
void printCheck() {
    for (int i = 0; i < n; i++)
        cout << check[i] << ' ';
    cout << '\n';
    
}
void printPQ() {
    printf("p, q, one: (%d, %d)\n", p, q);
}
void printAns() {
    printf("%d\n%d %d\n%d\n", k1, p+1, q+1, k2);
}

int shiftRight() {
    p = (p + 1) % n;
    q = (q + 1) % n;
    return 1;
}

void checkAnswer() {
    deque<int> dq;
    for (int i = 0; i < n; i++)
        dq.push_back(i+1);
    for (int i = 0; i < k1; i++) {
        dq.push_back(dq.front());
        dq.pop_front();
    }
    reverse(dq.begin()+p, dq.begin()+q+1);
    for (int i = 0; i < k2; i++) {
        dq.push_back(dq.front());
        dq.pop_front();
    }
    
    int arrflag = 0;
    for (int i = 0; i < n; i++)
        if (dq[i] != arr[i])
            arrflag = 1;

    if (k1 < 1 || k1 >= n) cout << "k1 error\n";
    if (k2 < 1 || k2 >= n) cout << "k2 error\n";
    if (p < 0 || p >= n-1) cout << "p error\n";
    if (q < 1 || q >= n) cout << "q error\n";
    if (arrflag) {cout << "result is not same\n";
    for (auto node : dq) cout << node << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

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
    
    if (zero != n) {
        for (int i = 0; i < n; i++) {
            int prev = (i == 0) ? n-1 : i-1;
            if (check[prev] == 1 && check[i] == 0) p = i;
        }
        q = (p + zero - 1) % n;
        
        int idx = -1;
        while (1) 
            if (check[++idx]) break;
        rs = arr[idx] + n - idx - 1;
        if (rs < n - 1) rs += n;
        else if (rs > 2*n - 2) rs -= n;
        
        do {
            k2 += shiftRight();
            rs--;
        } while (!(p < q && rs != 10));
        k1 = rs >= n ? rs - n : rs;
    }
    else {
        p = 0;
        q = n - 1;
        k2 = 1;
        while (arr[n-1-k2] - 1 <= 0) k2++;
        k1 = arr[n-1-k2] - 1;
    }

    printAns();
    // checkAnswer();
}