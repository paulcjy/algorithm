#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

int n, ans;

bool isPrime(int k) {
  if (k == 1) return false;
  for (int i = 2; i < k; i++) 
    if (k % i == 0) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int input; cin >> input;
    if (isPrime(input)) ans++;
  }
  cout << ans;
}