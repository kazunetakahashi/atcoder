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
// const int M = 1000000007;

const ll infty = 1000000000000000;

int N;
ll A[100010];
bool op[100010];
ll dp[100010][3];

int main () {
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> A[i];
    if (i < N-1) {
      char c;
      cin >> c;
      op[i] = (c == '+');
    }
  }
  dp[0][0] = A[0];
  dp[0][1] = -infty;
  dp[0][2] = -infty;
  for (auto i = 1; i < N; i++) {
    if (op[i-1]) {
      dp[i][2] = dp[i-1][2] + A[i];
      dp[i][1] = dp[i-1][1] - A[i];
      dp[i][0] = max(dp[i-1][1] - A[i], dp[i-1][0] + A[i]);
    } else {
      dp[i][2] = max(dp[i-1][2] + A[i], dp[i-1][1] + A[i]);
      dp[i][1] = max(dp[i-1][1] + A[i], dp[i-1][0] - A[i]);
      dp[i][0] = max(dp[i-1][1] + A[i], dp[i-1][0] - A[i]);
    }
  }
  /*
  for (auto i = 0; i < N; i++) {
    cerr << "dp[" << i << "] "
         << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
  }
  */
  cout << max({dp[N-1][0], dp[N-1][1], dp[N-1][2]}) << endl;
}
