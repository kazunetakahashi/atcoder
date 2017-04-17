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

int N, K;
ll a[100010];
ll memo[100010];
ll positive[100010];

ll sum(int i) { // i から i+K-1 までの和
  return memo[i+K] - memo[i];
}
ll positive_sum(int i, int j) { // i から j-1 までの和
  return positive[j] - positive[i];
}

int main () {
  cin >> N >> K;
  for (auto i = 0; i < N; i++) {
    cin >> a[i];
  }
  memo[0] = 0;
  for (auto i = 1; i <= N; i++) {
    memo[i] = memo[i-1] + a[i-1];
  }
  positive[0] = 0;
  for (auto i = 1; i <= N; i++) {
    if (a[i-1] >= 0) {
      positive[i] = positive[i-1] + a[i-1];
    } else {
      positive[i] = positive[i-1];
    }
  }
  ll ans = 0;
  for (auto i = 0; i < N-K+1; i++) {
    /*cerr << "i = " << i << endl;
    cerr << positive_sum(0, i) << " + "
         << sum(i) << " + "
         << positive_sum(i+K, N) << endl;*/
    ans = max(ans, positive_sum(0, i) +
              max(sum(i), (ll)0) + positive_sum(i+K, N));
  }
  cout << ans << endl;
}
