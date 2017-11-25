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

int N;
int D[60];

int main () {
  cin >> N;
  for (auto i = 0; i < N; ++i) {
    cin >> D[i];
  }
  int cnt[13];
  fill(cnt, cnt+13, 0);
  cnt[0] = 1;
  for (auto i = 0; i < N; ++i) {
    cnt[D[i]]++;
  }
  if (cnt[0] >= 2 || cnt[12] >= 2) {
    cout << 0 << endl;
    return 0;
  }
  for (auto i = 1; i <= 11; ++i) {
    if (cnt[i] >= 3) {
      cout << 0 << endl;
      return 0;      
    }
  }
  int res = 0;
  for (auto x = 0; x < (1 << 13); ++x) {
    set<int> S;
    for (auto i = 0; i <= 12; ++i) {
      if (cnt[i] == 2) {
        S.insert(i);
        S.insert((24-i)%24);
      } else if (cnt[i] == 1) {
        if (((x >> i) & 1) == 1) {
          S.insert(i);
        } else {
          S.insert((24-i)%24);
        }
      } else {
        assert(cnt[i] == 0);
      }
    }
    int ans = 100;
    for (auto e : S) {
      for (auto f : S) {
        if (e != f) {
          int sa = abs(e-f);
          sa = min(sa, 24-sa);
          ans = min(ans, sa);
        }
      }
    }
    res = max(res, ans);
  }
  cout << res << endl;
}
