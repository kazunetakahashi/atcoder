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

ll gcd(ll x, ll y)
{
  if (y == 0)
  {
    return x;
  }
  if (x < y)
  {
    return gcd(y, x);
  }
  return gcd(y, x % y);
}

bool solve(ll A, ll B, ll C, ll D)
{
  ll g = gcd(gcd(A, B), gcd(C, D));
  A /= g;
  B /= g;
  C /= g;
  D /= g;
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
  ll X = A - B;
  ll Y = A - C;
  ll g_bd = gcd(B, D);
  ll r_x = X % g_bd;
  if (Y - X > g_bd - r_x)
  {
    return false;
  }
  return true;
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