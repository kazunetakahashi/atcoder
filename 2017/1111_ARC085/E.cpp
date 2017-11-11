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
#include <chrono>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int main () {
  auto start = std::chrono::system_clock::now();
  random_device rd;
  mt19937 mt(rd());
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
  ll M = (1 << N/3);
  uniform_int_distribution<> rand(0, (1 << M) - 1);
  ll ans = 0;
  while (true) {
    ll i = rand(mt);
    vector<ll> x = a;
    for (auto j = 0; j < M; ++j) {
      if (((i >> j) & 1) == 1) {
        int k = j+1;
        for (auto l = 1; k*l <= N; ++l) {
          x[k*l] = 0;
        }      
      }
    }
    ll ret = 0;
    for (auto j = 1; j <= N; ++j) {
      ret += x[j];
    }
    if (ans < ret) {
      ans = ret;
    }
    auto end = std::chrono::system_clock::now();
    double timer = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    if (timer > 1800) break;
  }
  cout << ans << endl;
}
