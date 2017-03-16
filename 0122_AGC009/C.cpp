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

int N;
ll A, B;
ll S[100010];

ll X[100010];
ll Y[100010];
ll SX[100010];
ll SY[100010];
int kA[100010];
int kB[100010];

ll ans = 0;

ll calc_X(int i);
ll calc_Y(int i);
ll calc_SX(int i);
ll calc_SY(int i);

ll calc_X(int i) {
  if (X[i] >= 0) return X[i];
  if (kA[i+1] == -1) {
    return X[i] = 0;
  }
  return X[i] = calc_SY(min(kA[i+1], i-1));
}

ll calc_Y(int i) {
  if (Y[i] >= 0) return Y[i];
  if (kB[i+1] == -1) {
    return Y[i] = 0;
  }
  return Y[i] = calc_SX(min(kB[i+1], i-1));
}

ll calc_SX(int i) {
  if (SX[i] >= 0) return SX[i];
  return SX[i] = (calc_SX(i-1) + calc_X(i)) % M;
} 

ll calc_SY(int i) {
  if (SY[i] >= 0) return SY[i];
  return SY[i] = (calc_SY(i-1) + calc_Y(i)) % M;
} 

int main () {
  cin >> N >> A >> B;
  for (auto i = 0; i < N; i++) {
    cin >> S[i];
  }
  bool ok = true;
  for (auto i = 0; i < N-1; i++) {
    if (S[i+1] - S[i] < A) {
      ok = false;
      break;
    }
  }
  if (ok) ans++;
  ok = true;
  for (auto i = 0; i < N-1; i++) {
    if (S[i+1] - S[i] < B) {
      ok = false;
      break;
    }
  }
  if (ok) ans++;
  fill(X, X+N, -1);
  fill(Y, Y+N, -1);
  fill(SX, SX+N, -1);
  fill(SY, SY+N, -1);
  fill(kA, kA+N, -1);
  fill(kB, kB+N, -1);
  X[0] = 1;
  Y[0] = 1;
  SX[0] = X[0];
  SY[0] = Y[0];
  int l = 0;
  int r = 0;
  while (r < N) {
    if (S[r] - S[l] >= A) {
      kA[r] = l;
      cerr << "kA[" << r << "] = " << l << endl;
      l++;
    } else {
      r++;
    }
  }
  l = r = 0;
  while (r < N) {
    if (S[r] - S[l] >= B) {
      kB[r] = l;
      cerr << "kB[" << r << "] = " << l << endl;
      l++;
    } else {
      r++;
    }
  }
  for (auto i = 0; i < N-1; i++) {
    cout << "calc_X(" << i << ") = " << calc_X(i) << endl; 
  }
  for (auto i = 0; i < N-1; i++) {
    cout << "calc_Y(" << i << ") = " << calc_Y(i) << endl; 
  }
  ans += calc_SX(N-2) + calc_SY(N-2);
  ans %= M;
  cout << ans << endl;
}
