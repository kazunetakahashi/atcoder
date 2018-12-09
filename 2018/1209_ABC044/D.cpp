/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 12/9/2018, 10:40:14 PM
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
const ll infty = 100000000000000;

ll f(ll b, ll n)
{
  if (n < b)
  {
    return n;
  }
  return f(b, n / b) + n % b;
}

ll N, S;

int main()
{
  cin >> N >> S;
  if (N < S)
  {
    cout << -1 << endl;
    return 0;
  }
  if (N == S)
  {
    cout << N + 1 << endl;
    return 0;
  }
  for (auto b = 2; b * b <= N; b++)
  {
    if (f(b, N) == S)
    {
      cout << b << endl;
      return 0;
    }
  }
  ll ans = infty;
  for (auto p = 1; p * p <= N; p++)
  {
    ll q = S - p;
    if ((N - q) % p != 0)
    {
      continue;
    }
    ll b = (N - q) / p;
    if (!(0 <= q && q < b && p < b))
    {
      continue;
    }
    if (f(b, N) == S)
    {
      ans = min(ans, b);
    }
  }
  if (ans < infty)
  {
    cout << ans << endl;
  }
  else
  {
    cout << -1 << endl;
  }
}