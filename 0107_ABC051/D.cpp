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
const int infty = 1000000007;

int P[110][110];
int Q[110][110];

int main () {
  int N, M;
  cin >> N >> M;
  for (auto i = 0; i < N; i++) {
    for (auto j = 0; j < N; j++) {
      P[i][j] = infty;
    }
  }
  for (auto i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    P[a][b] = P[b][a] = c;
  }
  for (auto i = 0; i < N; i++) {
    for (auto j = 0; j < N; j++) {
      Q[i][j] = P[i][j];
    }
  }
  for (auto k = 0; k < N; k++) {
    for (auto i = 0; i < N; i++) {
      for (auto j = 0; j < N; j++) {
        if (i == j) continue;
        Q[i][j] = min(Q[i][j], Q[i][k] + Q[k][j]);
      }
    }
  }
  int ans = 0;
  for (auto i = 0; i < N; i++) {
    for (auto j = 0; j < N; j++) {
      if (P[i][j] < infty && P[i][j] > Q[i][j]) {
        ans++;
      }
    }
  }
  cout << ans/2 << endl;
  /*
  for (auto i = 0; i < N; i++) {
    for (auto j = 0; j < N; j++) {
      cerr << i << ", " << j << " : " << P[i][j] << " " << Q[i][j] << endl;
    }
  }
  */
}
