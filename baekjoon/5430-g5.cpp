#include <bits/stdc++.h>

using namespace std;

int t, n, x;
string p, arr, ans;
deque<int> d;

void split(string input, deque<int>& d) {
    input = input.substr(1, input.size()-2);
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, ','))
        d.push_back(stoi(temp));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        int dir = 1; // 1은 정방향, 2는 역방향
        int isError = 0;
        cin >> p >> n >> arr;
        split(arr, d);
        for (auto c : p) {
            if (c == 'R') dir = !dir;
            else {
                if (d.empty()) isError = 1;
                else {
                    if (dir) d.pop_front();
                    else d.pop_back();
                }
            }
        }

        if (isError) {
            cout << "error\n";
            continue;
        }
        
        ans = "";
        while (!d.empty()) {
            if (dir) {
                ans += to_string(d.front()) + ",";
                d.pop_front();
            }
            else {
                ans += to_string(d.back()) + ",";
                d.pop_back();
            }
        }
        ans = ans.substr(0, ans.size()-1);
        cout << '[' << ans << "]\n";
    }

    return 0;
}