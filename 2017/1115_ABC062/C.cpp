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

ll H, W;

ll two(int h, int w, int c) {
  if (c == 0) return h/2 * w;
  return w/2 * h;
}

ll solve() {
  ll ans = H * W;
  for (auto i = 1; i < H; ++i) {
    for (auto c = 0; c < 2; ++c) {
      ll X[3];
      X[0] = i * W;
      X[1] = two(H-i, W, c);
      X[2] = (H-i) * W - X[1];
      sort(X, X+3);
      ans = min(ans, X[2]-X[0]);      
    }
  }
  return ans;
}

int main () {
  cin >> H >> W;
  if (H%3 == 0 || W%3 == 0) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = min(H, W);
  ans = min(ans, solve());
  swap(H, W);
  ans = min(ans, solve());
  cout << ans << endl;
}
