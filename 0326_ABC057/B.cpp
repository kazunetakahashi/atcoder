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
const int infty = 1000000007;

int N, M;
int a[60], b[60], c[60], d[60];

int main () {
  cin >> N >> M;
  for (auto i = 0; i < N; ++i) {
    cin >> a[i] >> b[i];
  }
  for (auto i = 0; i < M; ++i) {
    cin >> c[i] >> d[i];
  }
  for (auto i = 0; i < N; ++i) {
    int ans = 0;
    int dist = infty;
    for (auto j = 0; j < M; ++j) {
      int di = abs(a[i] - c[j]) + abs(b[i] - d[j]);
      if (dist > di) {
        ans = j;
        dist = di;
      }
    }
    cout << ans+1 << endl;
  }
}
