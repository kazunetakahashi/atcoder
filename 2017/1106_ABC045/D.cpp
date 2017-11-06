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
#include <unordered_set>
#include <unordered_map>
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

int H, W, N;
typedef tuple<int, int> point;
set<point> S;

bool valid(int x, int y) {
  return 0 <= x && x < H && 0 <= y && y < W;
}

ll ans[10];

int main () {
  cin >> H >> W >> N;
  for (auto i = 0; i < N; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    S.insert(point(a, b));
  }
  for (auto x : S) {
    int a = get<0>(x);
    int b = get<1>(x);
    for (auto i = 0; i < 3; ++i) {
      for (auto j = 0; j < 3; ++j) {
        int ka = a - i;
        int kb = b - j;
        int cnt = 0;
        bool ok = true;
        for (auto k = 0; k < 3; ++k) {
          for (auto l = 0; l < 3; ++l) {
            int na = ka + k;
            int nb = kb + l;
            if (!valid(na, nb)) {
              ok = false;
            } else {
              if (S.find(point(na, nb)) != S.end()) {
                cnt++;
              }
            }
          }
        }
        if (ok) {
          ans[cnt]++;
        }
      }
    }
  }
  ll sum = 0;
  for (auto i = 1; i < 10; ++i) {
    ans[i] /= i;
    sum += ans[i];
  }
  ans[0] = (H-2) * (W-2) - sum;
  for (auto i = 0; i < 10; ++i) {
    cout << ans[i] << endl;
  }

}
