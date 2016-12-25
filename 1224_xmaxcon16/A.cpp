#include <iostream>
#include <iomanip> // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple> // get<n>(xxx)
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set> // S.insert(M);
// if (S.find(key) != S.end()) { }
// for (auto it=S.begin(); it != S.end(); it++) { }
// auto it = S.lower_bound(M);
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

typedef long long ll;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const int M = 1000000007;

int memo[100010];
bool memo_b[100010];
set<int> S;
const int infty = 1000000;

int solve(int a) {
  if (memo[a] != infty) return memo[a];
  auto it = S.lower_bound(a);
  it--;
  int x = *it;
  // cerr << "a = " << a << ", x = " << x << endl;
  int plus = solve(a-x) + 1;
  int minus = solve((x << 1) - a) + 2;
  memo_b[a] = (plus <= minus);
  return memo[a] = min(plus, minus);
}

int main() {
  fill(memo, memo+100010, infty);
  memo[0] = 0;
  S.insert(0);
  int t = 1;
  while (t < 100010) {
    memo[t] = 1;
    S.insert(t);
    t = (t << 1);
  }
  int N;
  cin >> N;
  solve(N);
  int l = 0;
  int r = N;
  ll ans = 0;
  bool isplus = true;
  while (S.find(r-l) == S.end()) {
    solve(r-l);
    auto it = S.lower_bound(r-l);
    it--;
    int x = *it;
    if (memo_b[r-l]) {
      cout << "? " << l << " " << l+x << endl;
      int temp;
      cin >> temp;
      if (isplus) {
        ans += temp;
      } else {
        ans -= temp;
      }
      l = l+x;
    } else {
      cout << "? " << l << " " << l+x << endl;
      int temp;
      cin >> temp;
      if (isplus) {
        ans += temp;
      } else {
        ans -= temp;
      }
      cout << "? " << r-x << " " << r << endl;
      cin >> temp;
      if (isplus) {
        ans += temp;
      } else {
        ans -= temp;
      }
      isplus = !isplus;
      int ll = l;
      l = r-x;
      r = ll+x;
    }
  }
  if (l != r) {
    cout << "? " << l << " " << r << endl;
    int temp;
    cin >> temp;
    if (isplus) {
      ans += temp;
    } else {
      ans -= temp;
    }
  }
  cout << "! " << ans << endl;
  /*
  int maxi = 0;
  for (auto i = 0; i < 100000; i++) {
    cout << i << ": " << solve(i) << endl;
    maxi = max(solve(i), maxi);
  }
  cout << "maxi = " << maxi << endl;
  */
}
