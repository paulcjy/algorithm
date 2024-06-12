#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

pair<int, int> walk(int n, int m) {
    if (n == 2) {
        switch (m) {
            case 1:
                return {1, 1};
            case 2:
                return {1, 2};
            case 3:
                return {2, 2};
            case 4:
                return {2, 1};
        }
    }

    n /= 2;
    int quarter = n * n;
    if (m <= quarter) {
        pair<int, int> xy = walk(n, m);
        return {xy.Y, xy.X};
    }
    else if (m <= 2*quarter) {
        pair<int, int> xy = walk(n, m - quarter);
        return {xy.X, xy.Y + n};
    }
    else if (m <= 3*quarter) {
        pair<int, int> xy = walk(n, m - 2*quarter);
        return {xy.X + n, xy.Y + n};
    }
    else {
        pair<int, int> xy = walk(n, m - 3*quarter);
        return {2*n - xy.Y + 1, n - xy.X + 1};
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    pair<int, int> ans = walk(n, m);
    cout << ans.X << ' ' << ans.Y;

    return 0;
}