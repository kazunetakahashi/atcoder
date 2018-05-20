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
// const int infty = 1000000007;

int N;
int P[200010];
int Q[200010];

int solve()
{
  int ans = 1;
  int lb = 0;
  for (auto i = 1; i < N; i++)
  {
    if (Q[i - 1] < Q[i])
    {
      ans = max(ans, i - lb + 1);
      // cerr << "lb = " << lb << ", i = " << i << endl;
    }
    else
    {
      lb = i;
    }
  }
  return N - ans;
}

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> P[i];
    P[i]--;
  }
  for (auto i = 0; i < N; i++)
  {
    Q[P[i]] = i;
  }
  int ans = solve();
  cout << ans << endl;
}