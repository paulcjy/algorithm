#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int n, l, a;
deque<pair<int, int>> d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    
    for (int i = 0; i < n; i++) {
        cin >> a;
        while (!d.empty() && d.back().Y >= a)
            d.pop_back();
        d.push_back({i, a});
        if (d.front().X <= i - l) d.pop_front();
        cout << d.front().Y << ' ';
    }
    return 0;
}