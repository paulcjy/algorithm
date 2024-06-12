#include <iostream>

using namespace std;

int input[1000010], mem[1000010];

int main() {
    int n, a, x, count = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        input[i] = a;
        mem[a]++;
    }

    cin >> x;

    for (int i = 0; i < n; i++) {
        mem[input[i]] = 0;
        if (mem[x-input[i]]) {
            count++;
            mem[x-input[i]] = 0;
        }
    }

    cout << count;

    return 0;
}
