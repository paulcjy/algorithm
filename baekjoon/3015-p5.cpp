#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

stack<pair<int, int>> s;
int n, input;
long long ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--) {
        cin >> input;
        int cnt = 1;
        while (!s.empty() && input >= s.top().X) {
            ans += s.top().Y;
            if (input == s.top().X) cnt += s.top().Y;
            s.pop();
        }
        if (!s.empty()) ans++;
        s.push({input, cnt});
    }

    cout << ans;
}