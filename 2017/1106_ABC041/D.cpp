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
// const ll M = 1000000007;

int N, M;
int x[300];
int y[300];
vector<int> V[20];
const int K = (1 << 16);
ll memo[K];

bool ok(int bit, int a) {
  for (auto b : V[a]) {
    if (((bit >> b) & 1) == 0) {
      return false;
    }
  }
  return true;
}

ll calc(int bit) {
  if (memo[bit] != -1) return memo[bit];
  ll ans = 0;
  for (auto i = 0; i < N; ++i) {
    if (((bit >> i) & 1) == 1) {
      int bit2 = bit - (1 << i);
      if (ok(bit2, i)) {
        // cerr << "ok bit2 = " << bit2 << ", i = " << i << endl;
        ans += calc(bit2);
      } else {
        // cerr << "!ok bit2 = " << bit2 << ", i = " << i << endl;
      }
    }
  }
  return (memo[bit] = ans); 
}

int main () {
  cin >> N >> M;
  for (auto i = 0; i < M; ++i) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  for (auto i = 0; i < M; ++i) {
    V[y[i]].push_back(x[i]);
  }
  fill(memo, memo+K, -1);
  memo[0] = 1;
  cout << calc((1 << N) -1) << endl;
  /*
  for (auto i = 0; i < (1<<N); ++i) {
    cerr << "calc(" << i << ") = " << calc(i) << endl;
  }
  */
}
