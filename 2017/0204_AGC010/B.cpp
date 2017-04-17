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

#define DEBUG 0; // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

ll N;
ll sum = 0;
ll times = 0;
ll A[100010];
ll B[100010];
ll D[100010];

int main () {
  cin >> N;
  for (auto i = 0; i < N; ++i) {
    cin >> A[i];
    sum += A[i];
  }
  ll NN = (N * (N+1) / 2);
  if (sum % NN != 0) {
    cout << "NO" << endl;
    return 0;
  }
  times = sum / NN;
  A[N] = A[0];
  for (auto i = 0; i < N; ++i) {
    B[i] = A[i+1] - A[i];
  }
  for (auto i = 0; i < N; ++i) {
    B[i] -= times;
  }
  for (auto i = 0; i < N; ++i) {
    if (B[i] <= 0 &&  B[i]%N == 0) {
      D[i] = B[i]/N;
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
