#include <iostream>

using namespace std;

int rooms[2][6];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, limit, count = 0;
    cin >> n >> limit;
    
    while (n--) {
        int sex, grade;
        cin >> sex >> grade;
        rooms[sex][grade-1]++;
    }
    
    for (auto &row : rooms) {
        for (auto &room : row) {
            if (room) {
                count += room / limit;
                if (room % limit) count++;
            }
        }
    }
    
    cout << count;
    
    return 0;
}