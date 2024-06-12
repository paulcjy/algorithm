#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c;
    
    while (1) {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        int sum = v[0] + v[1] + v[2];
        int max = *max_element(v.begin(), v.end());
        
        if (v[0] == 0 && v[1] == 0 && v[2] == 0) break;
        else if (max + max >= sum)
            cout << "Invalid";
        else if (v[0] == v[1] && v[1] == v[2] && v[2] == v[0])
            cout << "Equilateral";
        else if (v[0] != v[1] && v[1] != v[2] && v[2] != v[0])
            cout << "Scalene";
        else
            cout << "Isosceles";
    }
}