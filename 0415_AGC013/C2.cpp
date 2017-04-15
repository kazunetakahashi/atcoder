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

typedef tuple<double, double> res; // time, atlas

int N;
ll L, T;
ll X[100010];
int W[100010];
int ans[100010];

vector<ll> V[2];

int main () {
  cin >> N >> L >> T;
  for (auto i = 0; i < N; ++i) {
    cin >> X[i] >> W[i];
    W[i]--;
    V[W[i]].push_back(X[i]);
  }
  for (auto i = 0; i < N; ++i) {
    if (W[i] == 0) {
      ans[i] = X[i] + T%L;
      ans[i] %= L;
    } else {
      ans[i] = X[i] + L - T%L;
      ans[i] %= L;  
    }
  }
  int branch = 0;
  if (W[0] == 0) {
    int counter = V[1].size();
    branch += (T/L) * 2 * counter;
    branch %= N;
    int nokori = T%L;
    for (auto x : V[1]) {
      int kyori = (x + L - X[0])%L;
      if (kyori <= 2 * nokori) {
        branch++;
      }
      if (kyori + L <= 2 * nokori) {
        branch++;
      }
    }
    branch %= N;
  } else {
    int counter = V[0].size();
    branch += N - ((T/L) * 2 * counter)%N;
    branch %= N;
    int nokori = T%L;
    for (auto x : V[0]) {
      int kyori = (X[0] + L - x)%L;
      if (kyori <= 2 * nokori) {
        branch += (N-1);
      }
      if (kyori + L <= 2 * nokori) {
        branch += (N-1);
      }
    }
    branch %= N;
  }
  cerr << "branch = " << branch << endl;
  int memo = ans[0];
  cerr << "memo = " << memo << endl;
  sort(ans, ans+N);
  int zahyo = 0;
  if (W[0] == 0) {
    for (auto i = N-1; i >= 0; --i) {
      if (memo == ans[i]) {
        zahyo = (i + N - branch)%N;
        break;
      }
    }    
  } else {
    for (auto i = 0; i < N; ++i) {
      if (memo == ans[i]) {
        zahyo = (i + N - branch)%N;
        break;
      }
    }    
  }
  cerr << "zahyo = " << zahyo << endl;
  for (auto i = 0; i < N; ++i) {
    cout << ans[(zahyo + i)%N] << endl;
  }
}
