#include <bits/stdc++.h>

using namespace std;

stack<int> s;
int n, h;
long long ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--) {
        cin >> h;
        while (!s.empty() && h >= s.top())
            s.pop();
        ans += s.size();
        s.push(h);
    }
    
    cout << ans;
    return 0;
}