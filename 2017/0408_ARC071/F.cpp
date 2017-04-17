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
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
const ll M = 1000000007;

ll N;
ll DP[1000010];
ll SUM[1000010];

ll dp(int n);

ll sum(int n) {
  if (n < 0) return n;
  if (SUM[n] != -1) return SUM[n];
  return SUM[n] = (sum(n-1) + dp(n-1))%M;
}

ll dp(int n) {
  if (n < 0) return 1;
  if (DP[n] != -1) return DP[n];
  // k_1, k_2
  ll ans = (N-1) * (N-1);
  ans %= M;
  // 1
  ans += dp(n-1);
  ans %= M;
  // k_1, 1
  ans += sum(n-2-1+1) + M - sum(n-N-1);
  ans %= M;
  // cerr << "dp(" << n << ") = " << ans << endl;
  return DP[n] = ans;
}

int main () {
  cin >> N;
  fill(DP, DP+1000010, -1);
  fill(SUM, SUM+1000010, -1);
  DP[0] = 1;
  DP[1] = N;
  SUM[0] = 0;
  for (auto i = 0; i < N; ++i) {
    sum(i);
  }
  cout << dp(N) << endl;
}
