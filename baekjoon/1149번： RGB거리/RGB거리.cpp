/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1149                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: paulcjy <boj.kr/u/paulcjy>                  +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1149                           #+#        #+#      #+#    */
/*   Solved: 2024/04/26 19:34:44 by paulcjy       ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
// dp
#include <bits/stdc++.h>
using namespace std;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

enum Color { R, G, B };

int n;
int c[1005][3];
int d[1005][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> c[i][j];
    d[0][R] = c[0][R];
    d[0][G] = c[0][G];
    d[0][B] = c[0][B];

    for (int i = 1; i < n; i++) {
        d[i][R] = min(d[i-1][G], d[i-1][B]) + c[i][R];
        d[i][G] = min(d[i-1][R], d[i-1][B]) + c[i][G];
        d[i][B] = min(d[i-1][R], d[i-1][G]) + c[i][B];
    }
    cout << min({d[n-1][R], d[n-1][G], d[n-1][B]});
}