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

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const ll M = 1000000007;

int N;
int A[100010];
int X[100010];
int Y[3];

int main () {
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> A[i];
  }
  fill(X, X+100010, 0);
  for (auto i = 0; i < N; i++) {
    X[A[i]]++;
  }
  for (auto i = 0; i < 100010; i++) {
    if (X[i] >= 3) {
      if (X[i]%2 == 0) {
        X[i] = 2;
      } else {
        X[i] = 1;
      }
    }
  }
  fill(Y, Y+3, 0);
  for (auto i = 0; i < 100010; i++) {
    Y[X[i]]++;
  }
  int ans = 0;
  if (Y[2]%2 == 0) {
    ans = Y[1] + Y[2];
  } else {
    ans = Y[1] + Y[2] - 1;
  }
  cout << ans << endl;
}
