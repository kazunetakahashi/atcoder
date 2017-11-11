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
  int N;
  cin >> N;
  vector<ll> a(N+1, 0);
  for (auto i = 1; i <= N; ++i) {
    cin >> a[i];
  }
  for (auto i = N; i > N/3; --i) {
    ll val = 0;
    for (auto j = 1; i*j <= N; ++j) {
      val += a[i*j];
    }
    if (val < 0) {
      for (auto j = 1; i*j <= N; ++j) {
        a[i*j] = 0;
      }      
    }
  }
  /*
  cerr << "a : ";
  for (auto x : a) {
    cerr << x << " ";
  }
  cerr << endl;
  */
  int M = N/6 + 1;
  //cerr << "M = " << M << endl;
  ll ans = 0;
  for (auto i = 0; i < (1 << M); ++i) {
    vector<ll> x = a;
    for (auto j = 0; j < M; ++j) {
      if (((i >> j) & 1) == 1) {
        int k = j+1;
        for (auto l = 1; k*l <= N; ++l) {
          x[k*l] = 0;
        }      
      }
    }
    /*
    cerr << "i = " << i << ", x : ";
    for (auto y : x) {
      cerr << y << " ";
    }
    cerr << endl;
    */
    for (auto j = M+1; j <= N/3; ++j) {
      ll val = 0;
      for (auto l = 1; l*j <= N; ++l) {
        val += x[l*j];
      }
      if (val < 0) {
        for (auto l = 1; l*j <= N; ++l) {
          x[l*j] = 0;
        }      
      }
    }
    ll ret = 0;
    for (auto j = 1; j <= N; ++j) {
      ret += x[j];
    }
    ans = max(ans, ret);
  }
  cout << ans << endl;
}
