#include <bits/stdc++.h>
#define ll long long int
#define MOD 998244353
#define pii pair<int,int>
#define FASTIO cin.tie(0),ios_base::sync_with_stdio(0)
using namespace std;

int main(){
    FASTIO;
    int n,m;cin>>n>>m;
    vector<int> a(n);
    int cnt = 1;
    for(int i=1;i<=n-m;i++) cnt *= i;
    cout << "cnt: " << cnt << '\n';
    iota(a.begin(), a.end(), 1);
    int cur = 1;
    do{
        cur++;
        cout << cur << ' ' << cur % cnt << ' ';
        if(cnt > 1 && (cur % cnt) != 0) {
            cout << "continue\n";
            continue;
            }
        // for(int i=0;i<m;i++) cout<<a[i]<<' ';
        cout<<'\n';
    }while(next_permutation(a.begin(),a.end()));
}