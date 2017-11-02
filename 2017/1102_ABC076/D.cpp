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
int T;
int t[110];
int v[110];
int w[50000];

int main () {
  cin >> N;
  T = 0;
  for (auto i = 0; i < N; ++i) {
    cin >> t[i];
    t[i] *= 2;
    T += t[i];
  }
  for (auto i = 0; i < N; ++i) {
    cin >> v[i];
    v[i] *= 2;
  }
  w[0] = 0;
  w[T] = 0;
  for (auto i = 0; i <= T; ++i) {
    w[i] = i;
  }
  for (auto i = 0; i <= T; ++i) {
    w[i] = min(w[i], T - i);
  }
  int sum = 0;
  for (auto i = 0; i < N; ++i) {
    int all = sum + t[i];
    for (auto j = 0; sum-j >= 0; --j) {
      w[sum-j] = min(w[sum-j], v[i]+j);      
    }
    for (auto j = sum; j <= all; ++j) {
      w[j] = min(w[j], v[i]);
    }
    for (auto j = 0; all+j <= T; ++j) {
      w[all+j] = min(w[all+j], v[i]+j);      
    }
    sum += t[i];
  }
  double ans = 0;
  for (auto i = 0; i < T; ++i) {
    ans += ((double)w[i] + (double)w[i+1])/2;
  }
  cout << fixed << setprecision(10) << ans/4 << endl;
}
