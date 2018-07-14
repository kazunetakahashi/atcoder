/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-7-14 21:04:39
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
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(19920725));
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
// const ll M = 1000000007;

bool solve(ll A, ll B, ll C, ll D)
{
  if (B > A)
  {
    return false;
  }
  if (D < B)
  {
    return false;
  }
  if (A <= C)
  {
    return true;
  }
  double lb = ((double)A) / B - 1;
  double ub = ((double)A - C) / B;
  ll lower = ceil(lb);
  ll upper = floor(ub);
  if (lower <= upper && lower >= 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int T;
ll A[100010];
ll B[100010];
ll C[100010];
ll D[100010];

int main()
{
  cin >> T;
  for (auto i = 0; i < T; i++)
  {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }
  for (auto i = 0; i < T; i++)
  {
    bool ok = solve(A[i], B[i], C[i], D[i]);
    if (ok)
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }
}