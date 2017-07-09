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

int N, M;
int A[200010];
int X[200010];
int Y[200010];

int C[200010];
int S[200010];

int main () {
  cin >> N >> M;
  for (auto i = 0; i < N; ++i) {
    cin >> A[i];
    A[i]--;
  }
  for (auto i = 0; i < M; ++i) {
    cin >> X[i] >> Y[i];
    X[i]--;
    Y[i]--;
  }
  // assert(N <= 200 && M <= 200);
  fill(C, C+200010, 0);
  fill(S, S+N, 0);
  for (auto i = 0; i < N; ++i) {
    C[A[i]]++;
  }
  for (auto i = 0; i < N; ++i) {
    for (auto j = max(0, i-C[A[i]]+1); j <= i; ++j) {
      S[j]++;
    }
  }
  for (auto i = 0; i < N; ++i) {
    cerr << S[i] << " ";
  }
  cerr << endl;
  int ans = 0;
  for (auto i = 0; i < N; ++i) {
    if (S[i] == 0) ++ans;
  }
  for (auto k = 0; k < M; ++k) {
    int before = A[X[k]];
    int after = Y[k];
    S[before - C[before] + 1]--;
    if (S[before - C[before] + 1] == 0) {
      ans++;
    }
    S[after - C[after]]++;
    if (S[after - C[after]] > 0) {
      ans--;
    }    
    C[before]--;
    C[after]++;
    A[X[k]] = after;
    cout << ans << endl;
  }
}
