#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i < 1000000; i++) {
        int sum = i;
        int t = i;
        while (t > 0) {
            sum += t % 10;
            t = t / 10;
        }
        if (sum == n) {
            cout << i;
            break;
        }
    }
}