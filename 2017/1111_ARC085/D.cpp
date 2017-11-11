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

int a[2010];

int main () {
  int N, Z, W;
  cin >> N >> Z >> W;
  for (auto i = 0; i < N; ++i) {
    cin >> a[i];
  }
  int kaname = a[N-1];
  for (auto i = 0; i < N; ++i) {
    a[i] = abs(a[i] - a[N-1]);
  }
  reverse(a, a+N);
  int mini[2010];
  int maxi[2010];
  int tmin, tmax;
  mini[1] = a[1];
  maxi[1] = a[1];
  tmin = a[1];
  tmax = a[1];
  for (auto i = 2; i < N; ++i) {
    if (a[i] < tmin) {
      mini[i] = a[i];
      tmin = a[i];
    } else {
      mini[i] = mini[i-1];      
    }
    if (a[i] > tmax) {
      maxi[i] = a[i];
      tmax = a[i];
    } else {
      maxi[i] = maxi[i-1];      
    }
  }
  int ans = abs(W - kaname);
  for (auto i = 1; i < N; ++i) {
    ans = max(mini[i], ans);
  }
  cout << ans << endl;
}
