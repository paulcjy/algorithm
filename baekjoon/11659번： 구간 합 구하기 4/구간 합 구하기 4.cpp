/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11659                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: paulcjy <boj.kr/u/paulcjy>                  +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11659                          #+#        #+#      #+#    */
/*   Solved: 2024/04/26 20:19:49 by paulcjy       ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, m;
int num[100005];
int d[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    d[0] = 0;
    d[1] = num[1];
    for (int i = 2; i <= n; i++)
        d[i] = d[i-1] + num[i];
    while (m--) {
        int i, j;
        cin >> i >> j;
        cout << d[j] - d[i-1] << '\n';
    }
}