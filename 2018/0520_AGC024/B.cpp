/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-5-20 21:05:39
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>   // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set>
#include <random> // random_device rd; mt19937 mt(rd());
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
const int infty = 1000000007;

int N;
int P[200010];
int dp[200010];

int solve()
{
  fill(dp, dp + 200010, infty);
  for (auto i = 0; i < N; i++)
  {
    *lower_bound(dp, dp + N, P[i]) = P[i];
  }
  /*
  for (auto i = 0; i < N; i++)
  {
    cerr << "dp[" << i << "] = " << dp[i] << endl;
  }
  */
  cerr << (lower_bound(dp, dp + N, infty + 1) - dp) << endl;
  return N - (lower_bound(dp, dp + N, infty + 1) - dp);
}

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> P[i];
  }
  int ans = solve();
  cout << ans << endl;
}