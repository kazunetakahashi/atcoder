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
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;
 
typedef long long ll;
 
//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};
 
// const int C ;
const ll M = 1000000007;
const ll infty = 2000000000000000010;
 
int N;
ll A, B;
ll S[100010];
 
ll X[100010];
 
int kB[100010];
 
int underA[100010];
 
ll calc_X(int i);
ll calc_sum_DP(int i, int ka, int kb);
 
ll calc_X(int i) {
  if (X[i] >= 0) return X[i];
  if (S[i-1] - S[i-2] < A) {
    if (i-2 <= kB[i]) {
      return X[i] = calc_X(i-2);
    } else {
      return X[i] = 0;
    }
  } else {
    return X[i] = (calc_X(i-1) + calc_sum_DP(i-1, kB[i-1], kB[i]))%M;
  }
}
 
ll calc_sum_DP(int i, int ka, int kb) {
  ll ret = 0;
  /*
  for (auto j = i; j > kb+1; j--) {
    if (S[j] - S[j-1] < A) {
      return ret;
    }
  }
  */
  if (underA[i] - underA[kb+1] > 0) {
    return 0;
  }
  for (auto j = kb; j >= ka+1; j--) {
    ret += calc_X(j);
    ret %= M;
    if (S[j+1] - S[j] < A) {
      break;
    }
  }
  return ret;
}
 
int main () {
  cin >> N >> A >> B;
  if (A > B) swap(A, B);
  S[0] = -infty;
  for (auto i = 0; i < N; i++) {
    cin >> S[i+1];
  }
  N++;
  S[N++] = infty;
  for (auto i = 0; i < N; i++) {
    // cerr << "S[" << i << "] = " << S[i] << endl;
  }
  for (auto i = 2; i < N; i++) {
    if (S[i] - S[i-2] < A) {
      cout << 0 << endl;
      return 0;
    }
  }
  fill(kB, kB+N, -1);
  int l = 0;
  int r = 0;
  while (r < N) {
    if (S[r] - S[l] >= B) {
      kB[r] = l;
      // cerr << "kB[" << r << "] = " << l << endl;
      l++;
    } else {
      kB[r] = l-1;
      // cerr << "kB[" << r << "] = " << l-1 << endl;
      r++;
    }
  }
  fill(X, X+N, -1);
  X[0] = 1;
  X[1] = 1;
  /*for (auto i = 0; i < N; i++) {
    cerr << "X[" << i << "] = " << calc_X(i) << endl; 
    }*/
  underA[0] = 0;
  for (auto i = 0; i < N-1; i++) {
    if (S[i+1] - S[i] < A) {
      underA[i+1] = 1;
    } else {
      underA[i+1] = 0;
    }
  }
  for (auto i = 0; i < N; i++) {
    underA[i+1] += underA[i];
  }
  cout << calc_X(N-1) << endl;
}
