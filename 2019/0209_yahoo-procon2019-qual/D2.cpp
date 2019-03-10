#define DEBUG 1

/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 3/10/2019, 11:00:46 PM
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
#include <functional>
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(10101010));
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int L;
ll A[200010];
ll DP[200010][5];

ll near_even(ll x)
{
  if (x == 0)
  {
    return 2;
  }
  return x % 2;
}

ll near_odd(ll x)
{
  if (x % 2 == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  cin >> L;
  for (auto i = 0; i < L; i++)
  {
    cin >> A[i];
  }
  fill(&DP[0][0], &DP[0][0] + 200010 * 5, 0);
  for (auto i = 0; i < L; i++)
  {
    ll mini = DP[i][0];
    DP[i + 1][0] = mini + A[i];
    mini = min(DP[i][1], mini);
    DP[i + 1][1] = mini + near_even(A[i]);
    mini = min(DP[i][2], mini);
    DP[i + 1][2] = mini + near_odd(A[i]);
    mini = min(DP[i][3], mini);
    DP[i + 1][3] = mini + near_even(A[i]);
    mini = min(DP[i][4], mini);
    DP[i + 1][4] = mini + A[i];
  }
  ll ans = DP[L][0];
  for (auto i = 1; i < 5; i++)
  {
    ans = min(ans, DP[L][i]);
  }
  cout << ans << endl;
}