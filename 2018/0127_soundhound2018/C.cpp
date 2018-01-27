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

int main () {
  int R, C;
  cin >> R >> C;
  string S[50];
  for (auto i = 0; i < R; ++i) {
    cin >> S[i];
  }
  int ans = 0;
  for (auto k = 0; k < 2; ++k) {
    int tans = 0;
    for (auto i = 0; i < R; ++i) {
      for (auto j = 0; j < C; ++j) {
        if ((i+j)%2 == k && S[i][j] == '.') {
          tans++;
        }
      }
    }
    ans = max(tans, ans);
  }
  cout << ans << endl;
}
