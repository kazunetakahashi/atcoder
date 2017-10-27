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
const int infty = 1000000007;

int N, M, R;
int r[10];
int dist[210][210];
int A[100010];
int B[100010];
int C[100010];

int main () {
  cin >> N >> M >> R;
  for (auto i = 0; i < R; ++i) {
    cin >> r[i];
  }
  for (auto i = 0; i < M; ++i) {
    cin >> A[i] >> B[i] >> C[i];
    A[i]--;
    B[i]--;
  }
  fill(&dist[0][0], &dist[0][0]+210*210, infty);
  for (auto i = 0; i < N; ++i) {
    dist[i][i] = 0;
  }
  for (auto i = 0; i < M; ++i) {
    dist[A[i]][B[i]] = C[i];
    dist[B[i]][A[i]] = C[i];
  }
  for (auto k = 0; k < N; ++k) {
    for (auto i = 0; i < N; ++i) {
      if (k == i) continue;
      for (auto j = 0; j < N; ++j) {
        if (i == j) continue;
        if (k == j) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  sort(r, r+R);
  int ans = infty;
  do {
    int res = 0;
    for (auto i = 0; i < R-1; ++i) {
      res += dist[r[i]][r[i+1]];
    }
    ans = min(ans, res);
  } while (next_permutation(r, r+R));
  cout << ans << endl;
}
