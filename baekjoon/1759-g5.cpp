#include <bits/stdc++.h>

using namespace std;

int l, c;
char ch[15];
char buf[15];
int p[15];

bool isVowel(char c) {
    for (char v : {'a', 'e', 'i', 'o', 'u'})
        if (c == v) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;
    for (int i = 0; i < c; i++) 
        cin >> ch[i];
    sort(ch, ch+c);
    for (int i = l; i < c; i++) 
        p[i] = 1;
    do {
        int V = 0, C = 0, idx = 0;
        for (int i = 0; i < c; i++) 
            if (p[i] == 0) {
                if (isVowel(ch[i])) V++;
                else C++;
                buf[idx++] = ch[i];
            }
        if (!(V >= 1 && C >= 2)) continue;
        for (int i = 0; i < l; i++) 
            cout << buf[i];
        cout << '\n';
    } while (next_permutation(p, p+c));
}