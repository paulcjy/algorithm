#include <bits/stdc++.h>

using namespace std;

unsigned long long c[50];
bitset<8> W(0b10101010);
bitset<8> B(0b01010101);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;ㄹ
    }

    int ans = 64;
    for (int i = 0; i < n - 7; i++) {
        for (int j = 0; j < m - 7; j++) {
            int cnt1 = 0;
            int cnt2 = 0;
            for (int k = 0; k < 4; k++) {
                bitset<8> b1(c[i+2*k] >> j);
                bitset<8> b2(c[i+2*k+1] >> j);
                cnt1 += (b1^W).count() + (b2^B).count();
                cnt2 += (b1^B).count() + (b2^W).count();
            }
            int small = min(cnt1, cnt2);
            if (small < ans) ans = small;
        }
    }
    cout << ans;
}