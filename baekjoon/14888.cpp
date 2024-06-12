#include <bits/stdc++.h>

using namespace std;

enum Arithmatic {
    ADD,
    SUB,
    MUL,
    DIV
};

int n, M, m;
int num[15];
int ops[15];
int op[4];

void bt(int k) {
    if (k == n-1) {
        int result = num[0];
        int idx = 1;
        while (idx < n) {
            switch (ops[idx-1]) {
                case ADD:
                    result += num[idx++];
                    break;
                case SUB:
                    result -= num[idx++];
                    break;
                case MUL:
                    result *= num[idx++];
                    break;
                case DIV:
                    result /= num[idx++];
            }
        }
        M = max(M, result);
        m = min(m, result);
        return;
    }
    if (op[ADD]) {
        op[ADD]--;
        ops[k] = ADD;
        bt(k+1);
        op[ADD]++;
    }
    if (op[SUB]) {
        op[SUB]--;
        ops[k] = SUB;
        bt(k+1);
        op[SUB]++;
    }
    if (op[MUL]) {
        op[MUL]--;
        ops[k] = MUL;
        bt(k+1);
        op[MUL]++;
    }
    if (op[DIV]) {
        op[DIV]--;
        ops[k] = DIV;
        bt(k+1);
        op[DIV]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < 4; i++)
        cin >> op[i];
    M = 0x80000000;
    m = 0x7fffffff;
    bt(0);
    cout << M << '\n' << m;
}